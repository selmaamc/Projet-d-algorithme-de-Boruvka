#!/usr/bin/python


import time
from numpy.random import seed
from numpy.random import randint
import matplotlib.pyplot as plt


class Graphe:
    def __init__(self,  nbr_sommets):
        #self.list_aretes = list_aretes
        #self.list_sommets = list_sommets
       # self.a = len(graph)
        self.s = nbr_sommets
        graph = []
        #self.a = len(self.graph)

    def chercher(self, origine, i):#origine c'est pour identifier les ensembles
        if origine[i] == i:
            return i
        return self.chercher(origine, origine[i]) #on associe chaque 

    def union(self, origine, rang, a, b):
        a_orig = self.chercher(origine, a)
        b_orig = self.chercher(origine, b)
        if rang[a_orig] <= rang[b_orig]:
            origine[a_orig] = b_orig
            rang[a_orig] += 1
        elif rang[a_orig] > rang[b_orig]:
            origine[b_orig] = a_orig
        #else:
         #   origine[b_orig] = a_orig
          #  rang[a_orig] += 1


    def Kruskal(self):
        L = []
        origine = []
        rang = []
        i = 0
        S = 0
        self.graph = sorted(self.graph,key=lambda item: item[2])
        #print(self.graph)
        origine = []
        rang = []
        for j in range(self.s):
            origine.append(j)
            rang.append(0)
	while S < self.s-1 :
                src,dst,poids = self.graph[i]
                i += 1
                ens1 = self.chercher(origine, src)
                ens2 = self.chercher(origine ,dst)
                if ens1 != ens2:
    		    L.append([src,dst,poids])
                    self.union(origine, rang, ens1, ens2)
                    S += 1
    #print L






#L = [[[1,2,5],[2,3,6],[3,4,5],[4,1,8],[1,3,18]],[[1,2,5],[1,3,7],[2,4,8],[3,5,4],[3,6,2],[4,7,6],[4,6,4],[5,7,6]


def main():  # fonction pour generer des Graphs
    S = 4
    L = []
    elements = list()
    times = list()
    for i in range(1,10):
            for i in range(0,S-2):
                L.append(list((i,i+1,randint(1,50))))
                L.append(list((i,i+2,randint(1,50))))
            L.append(list((S-2,S-1,randint(1,50))))
            #L[i].append(random.randint(0,3))
            #L[i].append(random.randint(1,50))
           # print(L)
            start = time.clock()
            g = Graphe(S)
            g.graph = L
            g.Kruskal()
            end = time.clock()
            #print(L, "temps:", end-start)
            elements.append(S)
            times.append(end - start)
            S += 5
    plt.xlabel('List Length')
    plt.ylabel('Time Complexity')
    plt.plot(elements, times, label ='Kruskal')
    plt.grid()
    plt.legend()
    plt.show()

main()

