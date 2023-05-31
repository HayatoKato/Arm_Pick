import cv2

# カメラの設定
cap = cv2.VideoCapture(0)

# ArUco検出用モデル
dictionary = cv2.aruco.getPredefinedDictionary(cv2.aruco.DICT_4X4_50)
parameters = cv2.aruco.DetectorParameters()
detector = cv2.aruco.ArucoDetector(dictionary, parameters)

while True:

    # 画像取得
    ret, frame = cap.read()

    # ARマーカー認識
    corners, ids, _ = detector.detectMarkers(frame)
    frame = cv2.aruco.drawDetectedMarkers(frame, corners, ids)
    cv2.imshow('camera', frame)
    cv2.waitKey(1)
