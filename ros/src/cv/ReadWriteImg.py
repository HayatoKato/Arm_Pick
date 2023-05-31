import cv2

# カメラの登録
cap = cv2.VideoCapture(0)

# 画像取得
ret, frame = cap.read()

# 画像書き込み
cv2.imwrite("imgs/template2.jpg", frame)
