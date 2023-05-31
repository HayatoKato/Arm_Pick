import cv2
import numpy as np

# カメラの登録
cap = cv2.VideoCapture(0)

# ガンマ変換用の数値準備
gamma = 0.8
img2gamma = np.zeros((256, 1), dtype=np.uint8)
for i in range(256):
    img2gamma[i][0] = 255 * (float(i)/255) ** (1.0 / gamma)

while True:
    try:

        # 画像取得
        ret, frame = cap.read()  # 画像取得 [H, W, Ch]
        frame = cv2.LUT(frame, img2gamma)  # ガンマ変換
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        edges = cv2.Canny(gray, 200, 450, apertureSize=3)
        lines = cv2.HoughLinesP(
            edges, rho=1, theta=np.pi/360, threshold=60, minLineLength=10, maxLineGap=10)
        for line in lines:
            x1, y1, x2, y2 = line[0]
            red_line_img = cv2.line(frame, (x1, y1), (x2, y2), (0, 0, 255), 3)

        cv2.imshow("edges", edges)
        cv2.imshow("prediction", frame)
        cv2.waitKey(1)

    except KeyboardInterrupt:
        cap.release()
        cv2.destroyAllWindows()
        break
