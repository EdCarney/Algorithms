struct graph
{
    // List of all vertices in the graph.
    struct vertex *vertices;

    // List of all edges in the graph.
    struct edge *edges;

    // Adjacency list for the graph.
    struct vertex **adjacent;
};

struct vertex
{
    int id;
    int key;
};

struct edge
{
    int weight;

    // Starting node for the edge.
    struct vertex from;

    // Ending node for the edge.
    struct vertex to;
};

