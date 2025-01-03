const sumPlay = (playList) => {
    return playList.reduce((acc, val) => {
        acc += parseInt(val[1]);
        return acc;
    }, 0)
}

function solution(genres, plays) {
    var answer = [];
    const playMap = new Map();
    for (let i = 0; i < genres.length; i++) {
        if (playMap.has(genres[i])) {
            playMap.get(genres[i]).push([i, plays[i]])
        } else {
            playMap.set(genres[i], [[i, plays[i]]]);
        }
    }
    const playMapList = [...playMap.values()];
    playMapList.sort((a, b) => sumPlay(b) - sumPlay(a));
    playMapList.forEach(playList => {
        playList.sort((a,b) => b[1] - a[1]);
        answer.push(playList[0][0]);
        if (playList.length > 1) {
            answer.push(playList[1][0]);
        }
    })
    return answer;
}