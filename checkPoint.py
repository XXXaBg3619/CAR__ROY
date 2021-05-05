from node import *
import maze as mz
import score
import interface
import time

import numpy as np
import pandas
import time
import sys
import os

def main():
    maze = [0, 1, 2, 3, 4, 5, 4, 6, 7, 8, 9, 8, 10]
    point = score.Scoreboard("data/UID.csv", "team_NTUEE")
    interf = interface.interface()  # it will send "s" to arduino
    # TODO : Initialize necessary variables

    if (sys.argv[1] == '0'):
        print("Mode 0: for treasure-hunting")
        # TODO : for treasure-hunting, which encourages you to hunt as many scores as possible
        #shortest_path = maze.ShortestPath(int(float(str(maze.getStartPoint()))))
        #print("THE PATH:", shortest_path, "\n")
        
        i = 3
        while maze[i] != 10:
            UID = interf.ser.SerialReadByte()
            if interf.ser.SerialReadString() == "1":
                if i <= 3 or i == 5 or i == 6 or i == 11:
                    interf.ser.SerialWrite("1")
                elif i == 4: # 倒車入庫
                    interf.ser.SerialWrite("6")
                elif i == 6 or i == 8: # turn right
                    interf.ser.SerialWrite("3")
                elif i == 7: # turn left
                    interf.ser.SerialWrite("4")
                elif i == 9:# U-turn
                    while UID == '0' or UID == 31:
                        UID = interf.ser.SerialReadByte()
                    point.add_UID(UID)
                    interf.ser.SerialWrite("2")
                print(f"arrive at Node{maze[i]}", "i: ", i)
                    
                i += 1
        interf.ser.SerialWrite("5")
        while interf.ser.SerialReadByte() != "0":
            point.add_UID(UID)
            interf.end_process()
        interf.end_process()
        
        

    elif (sys.argv[1] == '1'):
        print("Mode 1: Self-testing mode.")
        # TODO: You can write your code to test specific function.

if __name__ == '__main__':
    main()