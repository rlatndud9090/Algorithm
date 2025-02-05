const isMatched = (id, banned) => {
    if (id.length !== banned.length) {
        // 길이가 다르면 false
        return false;
    }
    
    idList = id.split('');
    bannedList = banned.split('');
    
    for (let i = 0; i < bannedList.length; i += 1) {
        const char = bannedList[i];
        
        if (char !== '*' && char !== idList[i]) {
            // *이 아닌 글자가 매칭되지 않으면 false
            return false;
        }
    }
    
    return true;
}

function solution(userList, bannedList) {
    const selected = new Set();
    const result = new Set();
    
    const checkBannedUser = (userList, bannedList, selected) => {
        if (bannedList.length === 0) {
            result.add([...selected].sort().join(';'));
            return;
        }
        
        const newBannedList = [...bannedList];

        const bannedId = newBannedList.pop();
        for (let i = 0; i < userList.length; i += 1) {
            const user = userList[i];
            if (!selected.has(user) && isMatched(user, bannedId)) {
                selected.add(user);
                checkBannedUser(userList, newBannedList, selected);
                selected.delete(user);
            }
        }
    }
    
    checkBannedUser(userList, bannedList, selected)
    
    return result.size;
}