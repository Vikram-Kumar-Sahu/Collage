import java.util.*;

public class CountTheShapes {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Map<String,Integer> map = new HashMap<>();
        List<int[]> edges = new ArrayList<>();
        int id = 0;
        for (int i = 0; i < n; i++) {
            int x1 = sc.nextInt(), y1 = sc.nextInt(), x2 = sc.nextInt(), y2 = sc.nextInt();
            String p1 = x1 + "," + y1, p2 = x2 + "," + y2;
            if (!map.containsKey(p1)) map.put(p1, id++);
            if (!map.containsKey(p2)) map.put(p2, id++);
            edges.add(new int[]{map.get(p1), map.get(p2)});
        }
        int V = map.size();
        List<List<Integer>> g = new ArrayList<>();
        for (int i = 0; i < V; i++) g.add(new ArrayList<>());
        for (int[] e : edges) {
            g.get(e[0]).add(e[1]);
            g.get(e[1]).add(e[0]);
        }
        boolean[] vis = new boolean[V];
        int ans = 0;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                int[] res = dfs(i,g,vis);
                int v = res[0], e = res[1]/2;
                int faces = e - v + 1;
                if (faces > 0) ans += faces;
            }
        }
        System.out.println(ans);
    }

    static int[] dfs(int u, List<List<Integer>> g, boolean[] vis) {
        vis[u] = true;
        int v = 1, e = g.get(u).size();
        for (int nxt : g.get(u)) {
            if (!vis[nxt]) {
                int[] sub = dfs(nxt, g, vis);
                v += sub[0];
                e += sub[1];
            }
        }
        return new int[]{v,e};
    }
}
