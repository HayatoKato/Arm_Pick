import re
import cv2
import glob

files = glob.glob("imgs/*")
files = sorted(files)
for file in files:

    img = cv2.imread(file)
    print(file)

    file_split = re.split("[/_.]", file)
    lx = int(file_split[1].replace("lx", ""))
    ly = int(file_split[2].replace("ly", ""))
    rx = int(file_split[3].replace("rx", ""))
    ry = int(file_split[4].replace("ry", ""))
    print(img.shape)
    cv2.rectangle(img, (lx, ly), (rx, ry), (0, 255, 0))
    cv2.imshow("video", img)
    cv2.waitKey(1)
