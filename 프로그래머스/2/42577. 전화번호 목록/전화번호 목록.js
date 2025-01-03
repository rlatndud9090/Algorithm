function solution(phone_book) {
    phone_book.sort();
    for (let i = 0; i < phone_book.length - 1; i++) {
        const front = phone_book[i];
        const back = phone_book[i+1];
        if (back.startsWith(front)) {
            return false;
        }
    }
    return true;
}