function solution(tickets) {
    const graph = new Map();

    // 그래프 생성
    tickets.forEach(([from, to]) => {
        if (!graph.has(from)) graph.set(from, []);
        graph.get(from).push(to);
    });

    // 알파벳 순 정렬
    for (const [key, value] of graph) {
        value.sort();
    }

    const path = [];

    function dfs(node) {
        while (graph.has(node) && graph.get(node).length > 0) {
            dfs(graph.get(node).shift()); // 방문한 곳을 제거하면서 DFS 진행
        }
        path.push(node); // 백트래킹하면서 경로 추가
    }

    dfs("ICN");
    
    return path.reverse(); // 경로를 올바르게 정렬
}