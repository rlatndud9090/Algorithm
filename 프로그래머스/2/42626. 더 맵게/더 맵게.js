class MinHeap {
    constructor(arr) {
        this.heap = arr;
        this._buildHeap();
    }

    // 힙화 (배열을 MinHeap으로 만드는 함수)
    _buildHeap() {
        const startIdx = Math.floor(this.heap.length / 2) - 1;
        for (let i = startIdx; i >= 0; i--) {
            this._heapifyDown(i);
        }
    }

    // 힙 규칙을 유지하면서 아래로 내려가는 함수
    _heapifyDown(index) {
        const leftChildIdx = 2 * index + 1;
        const rightChildIdx = 2 * index + 2;
        let smallest = index;

        // 왼쪽 자식이 존재하고, 왼쪽 자식이 더 작은 경우
        if (leftChildIdx < this.heap.length && this.heap[leftChildIdx] < this.heap[smallest]) {
            smallest = leftChildIdx;
        }

        // 오른쪽 자식이 존재하고, 오른쪽 자식이 더 작은 경우
        if (rightChildIdx < this.heap.length && this.heap[rightChildIdx] < this.heap[smallest]) {
            smallest = rightChildIdx;
        }

        // 부모 노드가 더 큰 값이면 자식과 교환
        if (smallest !== index) {
            [this.heap[index], this.heap[smallest]] = [this.heap[smallest], this.heap[index]];
            this._heapifyDown(smallest); // 자식에 대해 재귀적으로 힙화
        }
    }

    // 루트 노드 삭제 후 MinHeap을 재구성하는 함수
    pop() {
        if (this.heap.length === 0) return null;
        const min = this.heap[0];
        const last = this.heap.pop(); // 마지막 요소를 꺼내고
        if (this.heap.length > 0) {
            this.heap[0] = last; // 마지막 요소를 루트로 올리고
            this._heapifyDown(0); // 힙 규칙을 유지하기 위해 아래로 내려간다
        }
        return min;
    }

    // 새로운 값 삽입
    push(value) {
        this.heap.push(value); // 마지막에 삽입
        this._heapifyUp(); // 힙 규칙을 유지하기 위해 위로 올린다
    }

    // 부모 노드가 자식보다 크면 부모와 자식 교환하며 위로 올라간다
    _heapifyUp() {
        let index = this.heap.length - 1;
        const element = this.heap[index];
        
        while (index > 0) {
            const parentIdx = Math.floor((index - 1) / 2);
            const parent = this.heap[parentIdx];

            if (element >= parent) break;
            
            this.heap[index] = parent;
            index = parentIdx;
        }

        this.heap[index] = element;
    }
    
    size() {
        return this.heap.length;
    }

    // 힙 출력
    print() {
        console.log(this.heap);
    }
}

function solution(scoville, K) {
    const heap = new MinHeap(scoville);
    let count = 0;
    let minScov = heap.pop();
    while (minScov < K) {
        if (!heap.size()) {
            return -1;
        }
        const secondMinScov = heap.pop();
        const newScov = minScov + secondMinScov * 2;
        heap.push(newScov);
        count += 1;
        minScov = heap.pop();
    }
    return count;
}