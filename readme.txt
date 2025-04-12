this is the main branch
database
api
jdbc
oop
programming

Conflict xảy ra khi nhiều branch cùng sửa cùng một phần của file (ở đây là readme.txt).
Khi merge các branch như database, oop, jdbc... vào main, Git không biết giữ nội dung nào do cùng chỉnh sửa một file nên xảy ra xung đột.

Khi xảy ra conflict, Git đánh dấu các phần bị xung đột trong file bằng <<<<<<<, =======, >>>>>>>.
Mở file readme.txt, giữ lại tất cả nội dung cần thiết của các branch (ví dụ: mỗi dòng this is...).
Sau đó dùng:
  git add readme.txt
  git commit -m "Giải quyết conflict khi merge các branch"
Cuối cùng tôi push lên main branch:
  git push origin main
