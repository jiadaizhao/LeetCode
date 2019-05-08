        nextMoves = -moves - graph[i][j]
                        if nextMoves >= 0:
                            heapq.heappush(pq, (-nextMoves, j))