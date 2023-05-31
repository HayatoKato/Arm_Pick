import cv2

# ArUco取得
aruco = cv2.aruco
dictionary = aruco.getPredefinedDictionary(aruco.DICT_4X4_50)

# ArUco生成と保存
for i in range(0, 50):
    fileName = "{:0>2}".format(i) + ".png"
    generator = aruco.generateImageMarker(dictionary, i, 500)
    cv2.imwrite("./ArUco/" + fileName, generator)
