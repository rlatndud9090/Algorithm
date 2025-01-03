function solution(bridge_length, weight, truck_weights) {
    const queue = Array(bridge_length).fill(0);
    let bridge_weight = 0;
    let time = 0;
    while(truck_weights.length > 0 || bridge_weight > 0) {
        time += 1;
        const passedTruck = queue.shift();
        bridge_weight -= passedTruck;
        if (truck_weights.length > 0 && bridge_weight + truck_weights[0] <= weight) {
            const nextTruck = truck_weights.shift();
            queue.push(nextTruck);
            bridge_weight += nextTruck;
        } else {
            queue.push(0);
        }
    }
    return time;
}