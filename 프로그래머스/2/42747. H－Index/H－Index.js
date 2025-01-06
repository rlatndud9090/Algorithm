function solution(citations) {
    let h = 0;
    citations.sort((a,b) => b-a).forEach((cit, index) => {
        if (cit > index) {
            h = index + 1;
        }
    });
    return h;
}