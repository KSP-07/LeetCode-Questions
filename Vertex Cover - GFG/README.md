# Vertex Cover
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given an undirected graph G return, the minimum number of vertexes that are needed so that every vertex is adjacent to the selected one.In short return the size of the vertex cover of the graph.</span></p>

<p><strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong><code>
N=5
M=6
edges[][]={{1,2}
{4, 1},
{2, 4},
{3, 4},
{5, 2},
{1, 3}}
<strong>Output:</strong>
3
<strong>Explanation:</strong>
Just pick 2,3,4.</code></span></pre>

<p><strong><span style="font-size:18px"><code>Example 2:</code></span></strong></p>

<pre><span style="font-size:18px"><code><strong>Input:</strong>
N=2
M=1
edges[][]={{1,2}}</code>
<strong>Output:</strong>
1
<strong>Explanation:</strong>
Pick either 1 or 2.</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:&nbsp;&nbsp;</strong><br>
You don't need to read input or print anything. Your task is to complete the function <strong>vertexCover()</strong>&nbsp;which takes the edge list and number of nodes of the graph<strong>&nbsp;</strong>as input parameters&nbsp;and returns the size of the vertex cover.</span><br>
<br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(M*LogN)<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(N*N)</span><br>
<br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1&lt;=N&lt;=31<br>
1&lt;=M&lt;=N*(N-1)/2<br>
1&lt;=edges[i][0],edges[i][1]&lt;=N</span></p>

<p>&nbsp;</p>
</div>