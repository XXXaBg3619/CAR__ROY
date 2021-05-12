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
    maze = mz.Maze("data/final_map.csv")
    point = score.Scoreboard("data/UID.csv", "ROY The Fire Truck!")
    #interf = interface.interface()  # it will send "s" to arduino
    # TODO : Initialize necessary variables

    if (sys.argv[1] == '0'):
        print("Mode 0: for treasure-hunting")
        # TODO : for treasure-hunting, which encourages you to hunt as many scores as possible
        shortest_path = maze.ShortestPath(int(float(str(maze.getStartPoint()))))
        print("THE PATH:", shortest_path, "\n")
        end_node = maze.FindEndNode()
        end_node.pop(0)
        
        i = 16
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
                    point.add_UID(UID)
                i += 1
        while True:
            if interf.ser.SerialReadString() == "1":
                interf.ser.SerialWrite("2")
                UID = interf.ser.SerialReadByte()
                while UID == "0" or  UID == "31":
                    UID = interf.ser.SerialReadByte()
                UID = str(hex(int(UID)))
                point.add_UID(UID)
                interf.end_process()
                break

    elif (sys.argv[1] == '1'):
        print("Mode 1: Self-testing mode.")
        # TODO: You can write your code to test specific function.
        action = ["1", "1", "1", "1", "6", "1", "3", "4", "3", "2", "1", "1"]
        i = 0
        while i < len(action) - 1:
            if interf.ser.SerialReadString() == "1":
                interf.ser.SerialWrite(action[i])
                if i in (4, 9):
                    UID = interf.ser.SerialReadByte()
                    while UID == '0' or UID == "31":
                        UID = interf.ser.SerialReadByte()
                    UID = str(hex(int(UID)))
                    point.add_UID(UID)
                print(f"arrive at Node{i + 1}", action[i])
                i += 1
        interf.ser.SerialWrite(action[i])
        while interf.ser.SerialReadByte() != "1":
            continue
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

    elif (sys.argv[1] == '3'): # for 指定專題
        print("Mode 3: Special mode.")
        nd_start = maze.getStartPoint()
        maze.nd_dict[nd_start].setExplored()
        maze.Explored = [nd_start]
        endPoints = maze.FindEndNode()
        print("End node:", endPoints)
        endPoints.pop(0)
        UnexploredCounter = len(endPoints)
        while UnexploredCounter > 0:
            print("from Node: ", nd_start)
            path = maze.BFS(nd_start)
            endPoint = path[-1]
            
            print("path: ", path)
            """i = 0
            while i < len(path) - 1:
                if interf.ser.SerialReadString() == "1":
                    nd_from = maze.nd_dict[path[i]]
                    nd_to = maze.nd_dict[path[i + 1]]
                    #interf.ser.SerialWrite(f"{maze.getAction(nd_from, nd_to)}")
                    print(f"arrive at Node{path[i]}")
                    i += 1
            UID = interf.ser.SerialReadByte()
            while UID == "0" or UID == "31":
                UID = interf.ser.SerialReadByte()"""
            print("arrive at endpoint: ", endPoint, "\n")
            """UID = str(hex(int(UID)))
            point.add_UID(UID)"""
            maze.nd_dict[endPoint].setExplored()
            nd_start = endPoint
            UnexploredCounter -= 1
        print()
        print("End Process")
        maze.Explored = []
        #interf.end_process()
    
    elif (sys.argv[1] == '4'):
        print("treasure-hunting mode")
        end_nodes = maze.FindEndNode()
        print("End node:", end_nodes)
        nd = maze.getStartPoint()
        while len(maze.Explored) < len(end_nodes) - 1:
            path = maze.special_BFS(nd)
            print("PATH:", path)
            maze.Explored.append(nd)
            nd = path[-1]
            """i = 0
            while i < len(path) - 1:
                if interf.ser.SerialReadString() == "1":
                    nd_from = maze.nd_dict[path[i]]
                    nd_to = maze.nd_dict[path[i + 1]]
                    interf.ser.SerialWrite(f"{maze.getAction(nd_from, nd_to)}")
                    print(f"arrive at Node{path[i]}")
                    i += 1
            UID = interf.ser.SerialReadByte()
            while UID == "0" or UID == "31":
                UID = interf.ser.SerialReadByte()
            print("arrive at node: ", nd, "\n")
            UID = str(hex(int(UID)))
            point.add_UID(UID)"""
        print("\n" + "end process")
        maze.Explored = []
        #interf.end_process()
        

if __name__ == '__main__':
    main()