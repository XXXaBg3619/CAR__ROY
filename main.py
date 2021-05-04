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
    maze = mz.Maze("data/small_maze.csv")
    point = score.Scoreboard("data/UID.csv", "team_4")
    interf = interface.interface()  # it will send "s" to arduino
    # TODO : Initialize necessary variables

    if (sys.argv[1] == '0'):
        print("Mode 0: for treasure-hunting")
        # TODO : for treasure-hunting, which encourages you to hunt as many scores as possible
        shortest_path = maze.ShortestPath(int(float(str(maze.getStartPoint()))))
        print("THE PATH:", shortest_path, "\n")
        
        i = 0
        while i < len(shortest_path) - 1:
            UID = interf.ser.SerialReadByte()
            print("UID:", UID)
            if interf.ser.SerialReadString() == "1":
                nd_from = maze.nd_dict[shortest_path[i]]
                nd_to = maze.nd_dict[shortest_path[i + 1]]
                print(f"arrive at Node{shortest_path[i]}")
                interf.ser.SerialWrite(f"{maze.getAction(nd_from, nd_to)}")
                i += 1
            elif UID != "0":
                point.add_UID(UID)
                i += 1
        while interf.ser.SerialReadByte() != "0":
            point.add_UID(UID)
            interf.end_process()
        
        

    elif (sys.argv[1] == '1'):
        print("Mode 1: Self-testing mode.")
        # TODO: You can write your code to test specific function.

if __name__ == '__main__':
    main()
