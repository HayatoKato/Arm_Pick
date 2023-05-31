import cv2
import numpy as np

# ガンマ変換用の数値準備
gamma = 2.5
img2gamma = np.zeros((256, 1), dtype=np.uint8)
for i in range(256):
    img2gamma[i][0] = 255 * (float(i)/255) ** (1.0 / gamma)


# カメラの登録
cap = cv2.VideoCapture(0)

# 背景画像読み込み
_, bg = cap.read()
gamma_bg = cv2.LUT(bg, img2gamma)  # ガンマ変換
gray_gamma_bg = cv2.cvtColor(gamma_bg, cv2.COLOR_BGR2GRAY)  # GRAY変換

rects = []
while True:
    try:
        # 画像取得
        ret, fg = cap.read()  # 画像取得
        gamma_fg = cv2.LUT(fg, img2gamma)  # ガンマ変換
        gray_gamma_fg = cv2.cvtColor(gamma_fg, cv2.COLOR_BGR2GRAY)  # GRAY変換

        # 画像差分
        img_diff = cv2.absdiff(gray_gamma_bg, gray_gamma_fg)
        _, object_mask = cv2.threshold(img_diff, 35, 255, cv2.THRESH_BINARY)

        # 輪郭検出
        contours, hierarchy = cv2.findContours(
            object_mask, cv2.RETR_LIST, cv2.CHAIN_APPROX_NONE)

        # マスクチェック
        object_mask_contour = np.zeros_like(object_mask)
        for i, contour in enumerate(contours):
            area = cv2.contourArea(contour, True)
            if abs(area) > 5:
                object_mask_contour = cv2.fillPoly(object_mask_contour,
                                                   [contours[i][:, 0, :]], 255, lineType=cv2.LINE_8, shift=0)

        # マスクからBDを算出
        frame_bd = np.copy(fg)
        arg_mask = np.argwhere(object_mask_contour == 255)
        if len(arg_mask) > 0:
            argmin_x, argmin_y = np.min(arg_mask[:, 1]), np.min(arg_mask[:, 0])
            argmax_x, argmax_y = np.max(arg_mask[:, 1]), np.max(arg_mask[:, 0])
            cv2.rectangle(frame_bd, (argmin_x, argmin_y),
                          (argmax_x, argmax_y), (0, 255, 0))
            area = (argmax_x - argmin_x) * (argmax_y - argmin_y)
            if (1000 <= area) and (area <= 7000):
                flag = True
                for rect in rects:
                    if (abs(rect[0] - argmin_x) <= 2) and (abs(rect[1] - argmin_y) <= 2) and (abs(rect[2] - argmax_x) <= 2) and (abs(rect[3] - argmax_y) <= 2):
                        flag = False
                        break
                if flag:
                    rects.append([argmin_x, argmin_y, argmax_x, argmax_y])
                    cv2.imwrite(
                        f"imgs/lx{argmin_x}_ly{argmin_y}_rx{argmax_x}_ry{argmax_y}.jpg", fg)

        # 画像表示
        cv2.imshow("bg", bg)
        cv2.imshow("frame_bd", frame_bd)
        cv2.imshow("gamma_fg", gamma_fg)
        cv2.imshow("object_mask_contour", object_mask_contour)
        cv2.waitKey(1)

    except KeyboardInterrupt:
        cap.release()
        cv2.destroyAllWindows()
        break
