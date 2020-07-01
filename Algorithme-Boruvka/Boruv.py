#!/usr/bin/python


import time 
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
    

    def boruvka(self):
        L = []
        origine = []
        rang = []
        ens_min = [] #index d'arete qui a le poids minimum
        S = self.s
        poidsmst = 0
        G = len(self.graph)
        for i in range (self.s):
            origine.append(i)
            rang.append(0)
            ens_min = [-1] * self.s
        while S > 1:
            for i in range(G):
                src = self.graph[i][0]
                dst = self.graph[i][1]
                poids = self.graph[i][2]
                ens1 = self.chercher(origine, src)
                ens2 = self.chercher(origine, dst)
                if ens1 != ens2:
                    if ens_min[ens1] == -1 or ens_min[ens1][2]>poids:
                        ens_min[ens1] = [src, dst, poids]
                    if ens_min[ens2] == -1 or ens_min[ens2][2]>poids:
                        ens_min[ens2] = [src, dst, poids]
            for j in range (self.s):
                if ens_min[j] != -1:
                    src, dst, poids = ens_min[j]
                    ens1 = self.chercher(origine, src)
                    ens2 = self.chercher(origine, dst)
                    if ens1 != ens2:
                        poidsmst += poids
                        self.union(origine, rang, ens1, ens2)
                        L += [src,dst]
                        S = S - 1
            ens_min = [-1]*self.s
        #print L
        #print poidsmst



##############



##L = [[0, 1, 1], [0, 2,2], [1, 2, 4], [1, 3, 3], [2, 3, 5], [2, 4, 1], [3, 4, 2]]
#g = Graphe(5)
#g.graph = L
#g.boruvka() 

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
         #   print(L)
            start = time.clock()
            g = Graphe(S)
            g.graph = L
            g.boruvka()
            end = time.clock()
            #print(L, "temps:", end-start)
            elements.append(S)
            times.append(end - start)
            S += 5
    plt.xlabel('List Length')
    plt.ylabel('Time Complexity')
    plt.plot(elements, times, label ='Boruvka')
    plt.grid()
    plt.legend()
    plt.show()

main()


