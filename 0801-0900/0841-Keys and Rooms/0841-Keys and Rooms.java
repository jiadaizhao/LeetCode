class Solution {
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        Set<Integer> visited = new HashSet<Integer>();
        Queue<Integer> Q = new LinkedList<Integer>();
        Q.offer(0);
        visited.add(0);
        while (!Q.isEmpty()) {
            int index = Q.poll();
            for (int k : rooms.get(index)) {
                if (!visited.contains(k)) {
                    Q.offer(k);
                    visited.add(k);
                }
            }
        }
        return visited.size() == rooms.size();
    }
}
