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
    maze = mz.Maze("data/medium_maze.csv")
    point = score.Scoreboard("data/UID.csv", "team_4")
    interf = interface.interface()  # it will send "s" to arduino
    # TODO : Initialize necessary variables

    if (sys.argv[1] == '0'):
        print("Mode 0: for treasure-hunting")
        # TODO : for treasure-hunting, which encourages you to hunt as many scores as possible
        shortest_path = maze.ShortestPath(int(float(str(maze.getStartPoint()))))
        print("THE PATH:", shortest_path, "\n")
        end_node = maze.FindEndNode()
        end_node.pop(0)
        
        i = 0
        while i < len(shortest_path) - 1:
            if interf.ser.SerialReadString() == "1":
                nd_from = maze.nd_dict[shortest_path[i]]
                nd_to = maze.nd_dict[shortest_path[i + 1]]
                print(f"arrive at Node{shortest_path[i]}")
                interf.ser.SerialWrite(f"{maze.getAction(nd_from, nd_to)}")
                if shortest_path[i] in end_node :
                    UID = interf.ser.SerialReadByte()
                    while UID == "0" or UID == "31":
                        UID = interf.ser.SerialReadByte()
                    UID = str(hex(int(UID)))
                    print("讀到的:", UID)
                    point.add_UID(UID)
                i += 1
        if interf.ser.SerialReadString() == "1":
            interf.ser.SerialWrite("2")
            UID = interf.ser.SerialReadByte()
            while UID == "0" or  UID == "31":
                UID = interf.ser.SerialReadByte()
            UID = str(hex(int(UID)))
            point.add_UID(UID)
            interf.end_process()
        
        

    elif (sys.argv[1] == '1'):
        print("Mode 1: Self-testing mode.")
        # TODO: You can write your code to test specific function.
        path = ["1", "6", "1"]
        i = 0
        while i < len(path):
            if interf.ser.SerialReadString() == "1":
                interf.ser.SerialWrite(path[i])
                print(path[i])
                i += 1
        if interf.ser.SerialReadString() == "1":
            interf.end_process()

    elif (sys.argv[1] == '2'):
        print("test medium")
        shortest_path = maze.ShortestPath(int(float(str(maze.getStartPoint()))))
        print("THE PATH:", shortest_path, "\n")
        
        i = 0
        while i < len(shortest_path) - 1:
            if interf.ser.SerialReadString() == "1":
                nd_from = maze.nd_dict[shortest_path[i]]
                nd_to = maze.nd_dict[shortest_path[i + 1]]
                print(f"arrive at Node{shortest_path[i]}")
                interf.ser.SerialWrite(f"{maze.getAction(nd_from, nd_to)}")
                i += 1
        while interf.ser.SerialReadString() == "1":
            interf.end_process()
        

if __name__ == '__main__':
    main()
