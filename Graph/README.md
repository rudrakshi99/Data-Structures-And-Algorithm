# Graph Theory

## Eulerian path and circuit 

### Eulerian path:
Eulerian Path is a path in graph that visits every edge exactly once. 

### Eulerian Circuit:
 
Eulerian Circuit is an Eulerian Path which starts and ends on the same vertex. 

**1. Undircted Graph**

    * Eulerian circuit -> each node of even degree
    * Eulerian path    -> (n-2) nodes of even degee + exactly 2 nodes of odd degree
    
**2. Directed Graph**

    * Eulerian circuit -> each node indegree == outdegree
    * Eulerian path    -> (n-2) nodes indegree == outdegree + 1 node indegree = outdegree+1 + 1 node outdegree = indegree+1
