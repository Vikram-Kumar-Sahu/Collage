import java.util.*;

public class FrankensteinPotion {
    static Map<String, List<List<String>>> recipes = new HashMap<>();
    static Map<String, Integer> memo = new HashMap<>();
    static Set<String> visiting = new HashSet<>();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = Integer.parseInt(sc.nextLine().trim());
        if (N <= 0 || N >= 20) {
            System.out.print(-1);
            sc.close();
            return;
        }
        for (int i = 0; i < N; i++) {
            String line = sc.nextLine().trim();
            String[] parts = line.split("=");
            String potion = parts[0];
            String[] ingredients = parts[1].split("\\+");
            recipes.putIfAbsent(potion, new ArrayList<>());
            recipes.get(potion).add(Arrays.asList(ingredients));
        }
        String target = sc.nextLine().trim();
        sc.close();
        int result = minOrbs(target);
        if (result == Integer.MAX_VALUE) {
            System.out.print(-1);
        } else {
            System.out.print(result);
        }
    }

    static int minOrbs(String potion) {
        if (memo.containsKey(potion)) return memo.get(potion);
        if (!recipes.containsKey(potion)) {
            memo.put(potion, 0);
            return 0;
        }
        if (visiting.contains(potion)) return Integer.MAX_VALUE;
        visiting.add(potion);
        int minCost = Integer.MAX_VALUE;
        for (List<String> ingredients : recipes.get(potion)) {
            int cost = ingredients.size() - 1;
            boolean valid = true;
            for (String ing : ingredients) {
                int ingCost = minOrbs(ing);
                if (ingCost == Integer.MAX_VALUE) {
                    valid = false;
                    break;
                }
                cost += ingCost;
            }
            if (valid) minCost = Math.min(minCost, cost);
        }
        visiting.remove(potion);
        memo.put(potion, minCost);
        return minCost;
    }
}
