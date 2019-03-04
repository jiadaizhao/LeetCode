import java.util.HashMap;
import java.util.HashSet;
import java.util.Queue;
import java.util.LinkedList;
import java.util.Set;
import java.util.Map;

class Solution {
    public int numBusesToDestination(int[][] routes, int S, int T) {
        if (S == T) return 0;
        int n = routes.length;
        Map<Integer, HashSet<Integer>> stationToBus = new HashMap();
        Set<Integer> visitedBus = new HashSet();
        Set<Integer> visitedStation = new HashSet();

        for (int i = 0; i < n; ++i) {
            for (int station : routes[i]) {
                HashSet<Integer> buses = stationToBus.getOrDefault(station, new HashSet<>());
                buses.add(i);
                stationToBus.put(station, buses);
            }
        }

        Queue<Integer> Q = new LinkedList();
        Q.offer(S);
        visitedStation.add(S);

        int step = 0;
        while (!Q.isEmpty()) {
            int qs = Q.size();
            ++step;
            for (int i = 0; i < qs; ++i) {
                int s = Q.poll();
                for (int nb : stationToBus.get(s)) {
                    if (!visitedBus.contains(nb)) {
                        visitedBus.add(nb);
                        for (int ns : routes[nb]) {
                            if (ns == T) {
                                return step;
                            }
                            if (!visitedStation.contains(ns)) {
                                Q.offer(ns);
                                visitedStation.add(ns);
                            }                            
                        }
                    }
                }
            }
        }

        return -1;
    }
}
