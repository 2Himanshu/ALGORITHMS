class MultiStage
{
    static int N = 12;
    static int INF = Integer.MAX_VALUE;

    public static int shortestDist(int[][] graph)
    {
        int[] dist = new int[N];
        dist[N - 1] = 0;
        for (int i = N - 2; i >= 0; i--)
        {
            dist[i] = INF;
            for (int j = i; j < N; j++)
            {
                if (graph[i][j] == INF)
                {
                    continue;
                }
                dist[i] = Math.min(dist[i], graph[i][j]
                        + dist[j]);
            }
        }
 
        return dist[0];
    }
 
    // Driver code
    public static void main(String[] args)
    {
        int[][] graph = new int[][]{{INF, 9, 7, 3, 2, INF, INF, INF, INF, INF, INF, INF},
                                    {INF, INF, INF, INF, INF, 4, 2, 11, INF, INF, INF, INF},
                                    {INF, INF, INF, INF, INF, 2, 7, INF, INF, INF, INF, INF},
                                    {INF, INF, INF, INF, INF, INF, INF, 11, INF, INF, INF, INF},
                                    {INF, INF, INF, INF, INF, INF, 11, 8, INF, INF, INF, INF},
                                    {INF, INF, INF, INF, INF, INF, INF, INF, 6, 5, INF, INF},
                                    {INF, INF, INF, INF, INF, INF, INF, INF, 4, 3, INF, INF},
                                    {INF, INF, INF, INF, INF, INF, INF, INF, INF, 5, 6, INF},
                                    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 4},
                                    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 2},
                                    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 5}
                                    };
 
        System.out.println("Minimum Cost Obtained: " + shortestDist(graph));
    }
}