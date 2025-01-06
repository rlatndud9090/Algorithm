class MaxHeap {
    constructor() {
        this.heap = [];
    }
    
    getAnswer() {
        return this.heap.reduce((acc, val) => acc + val*val, 0);
    }

    // 요소 삽입
    insert(value) {
        this.heap.push(value);
        this._heapifyUp();
    }

    // 최대값 제거 및 반환
    pop() {
        if (this.size() === 0) return null;
        if (this.size() === 1) return this.heap.pop();

        const max = this.heap[0];
        this.heap[0] = this.heap.pop();
        this._heapifyDown();
        return max;
    }

    // 최대값 조회
    peek() {
        return this.size() > 0 ? this.heap[0] : null;
    }

    // 힙의 크기 반환
    size() {
        return this.heap.length;
    }

    // 내부 메서드: 삽입 시 힙 유지
    _heapifyUp() {
        let index = this.heap.length - 1;
        const element = this.heap[index];

        while (index > 0) {
            const parentIndex = Math.floor((index - 1) / 2);
            const parent = this.heap[parentIndex];

            if (element <= parent) break;

            this.heap[index] = parent;
            this.heap[parentIndex] = element;
            index = parentIndex;
        }
    }

    // 내부 메서드: 삭제 시 힙 유지
    _heapifyDown() {
        let index = 0;
        const length = this.heap.length;
        const element = this.heap[index];

        while (true) {
            const leftChildIndex = 2 * index + 1;
            const rightChildIndex = 2 * index + 2;
            let leftChild, rightChild;
            let swapIndex = null;

            if (leftChildIndex < length) {
                leftChild = this.heap[leftChildIndex];
                if (leftChild > element) swapIndex = leftChildIndex;
            }

            if (rightChildIndex < length) {
                rightChild = this.heap[rightChildIndex];
                if (
                    (swapIndex === null && rightChild > element) ||
                    (swapIndex !== null && rightChild > leftChild)
                ) {
                    swapIndex = rightChildIndex;
                }
            }

            if (swapIndex === null) break;

            this.heap[index] = this.heap[swapIndex];
            this.heap[swapIndex] = element;
            index = swapIndex;
        }
    }
}

function solution(n, works) {
    const sumOfWork = works.reduce((a,v) => a+v);
    if (sumOfWork <= n) {
        return 0;
    }
    const maxHeap = new MaxHeap();
    works.forEach(work => maxHeap.insert(work));
    for (let i = 0; i < n; i++) {
        const maxWork = maxHeap.pop();
        maxHeap.insert(maxWork - 1);
    }
    return maxHeap.getAnswer();
}