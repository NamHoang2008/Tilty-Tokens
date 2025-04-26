# Tilty-Tokens
Game này được tạo ra bởi tbradm. Bạn có thể chơi game này trên Roblox.
---
- Vấn đề:

  Cho một ma trận gồm 7 x 7 ô, ma trận con 5 x 5 được bao quanh bởi bức tường. Trong ma trận con, gồm có:
  - `'.'` - Ô trống.
  - `'X'` - Bức tường.
  - `'O'` - Lối thoát
  - `'G'` - Xu xanh lá.
  - `'B'` - Xu xanh nước.
  ---
  Bạn có thể nghiêng `Tất cả` đồng xu thông qua 4 hướng: `Trên`, `Dưới`, `Phải`, `Trái`.
  - Khi nghiêng thì tất cả đồng xu phải di chuyển hết cho đến khi gặp vật cản và dừng lại.
  ---
  **Hãy in ra `Bất kỳ` nước đi ngắn nhất nào để đưa hết tất cả `Xu xanh lá` vào `Lối thoát`.**
  - Một nước đi không hợp lí nếu đưa `Xu xanh nước` vào `Lối thoát`.
  ---
  Ví dụ 1:
  - INPUT: [['X','X','X','X','X','X','X'],['X','G','X','.','.','.','X'],['X','.','.','.','.','.','X'],['X','.','.','O','.','.','X'],['X','.','.','.','.','.','X'],['X','.','.','X','.','.','X'],['X','X','X','X','X','X','X']]
  - OUTPUT: "DRURULD"
  - GIẢI THÍCH: 
