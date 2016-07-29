import cv2
import numpy as np

'''
img = cv2.imread('a.jpg')

px = img[100,100]
#print px

img.item(10,10,2)     # Accede al valor rojo del pixel 10,10
img.itemset((10,10,2),100) # Cambie el valor

print img.shape # It returns a tuple of number of rows, columns and channels 
print img.size # Total number of pixels
print img.dtype # Image datatype

# ROI
#temp = img[280:340,330:390]
#img[273:333,100:160] = temp

b,g,r = cv2.split(img) # Divide los canales de la imagen
img = cv2.merge((b,g,r)) # Funde los canales denuevo

b = img[:,:,0] # Toma el canal azul de la imagen

img[:,:,2] = 0 # Cambia el canal rojo de todos los pixeles a cero

cv2.imshow('Muestra',img)
cv2.waitKey()

If you want to create a border around the image, something like a photo frame, you can use cv2.copyMakeBorder() function. But it has more applications for convolution operation, zero padding etc. This function takes following arguments:

        src - input image

        top, bottom, left, right - border width in number of pixels in corresponding directions

        borderType - Flag defining what kind of border to be added. It can be following types:
                cv2.BORDER_CONSTANT - Adds a constant colored border. The value should be given as next argument.
                cv2.BORDER_REFLECT - Border will be mirror reflection of the border elements, like this : fedcba|abcdefgh|hgfedcb
                cv2.BORDER_REFLECT_101 or cv2.BORDER_DEFAULT - Same as above, but with a slight change, like this : gfedcb|abcdefgh|gfedcba
                cv2.BORDER_REPLICATE - Last element is replicated throughout, like this: aaaaaa|abcdefgh|hhhhhhh
                cv2.BORDER_WRAP - Cant explain, it will look like this : cdefgh|abcdefgh|abcdefg

        value - Color of border if border type is cv2.BORDER_CONSTANT
replicate = cv2.copyMakeBorder(img1,10,10,10,10,cv2.BORDER_REPLICATE)
'''

#img2 = cv2.imread('xfce.png')
#dst = cv2.addWeighted(img,0.7,img2,0.3,0)

#cv2.imshow('dst',dst)
#cv2.waitKey(0)
#cv2.destroyAllWindows()

'''
# Load two images
img1 = cv2.imread('messi5.jpg')
img2 = cv2.imread('opencv_logo.png')

# I want to put logo on top-left corner, So I create a ROI
rows,cols,channels = img2.shape
roi = img1[0:rows, 0:cols ]

# Now create a mask of logo and create its inverse mask also
img2gray = cv2.cvtColor(img2,cv2.COLOR_BGR2GRAY)
ret, mask = cv2.threshold(img2gray, 10, 255, cv2.THRESH_BINARY)
mask_inv = cv2.bitwise_not(mask)

# Now black-out the area of logo in ROI
img1_bg = cv2.bitwise_and(roi,roi,mask = mask_inv)

# Take only region of logo from logo image.
img2_fg = cv2.bitwise_and(img2,img2,mask = mask)

# Put logo in ROI and modify the main image
dst = cv2.add(img1_bg,img2_fg)
img1[0:rows, 0:cols ] = dst

cv2.imshow('res',img1)
cv2.waitKey(0)
cv2.destroyAllWindows()
'''

#cv2.cvtColor(input_image, flag)
#cv2.COLOR_BGR2HS,cv2.COLOR_BGR2GRAY

'''
# Reconocer y seguir el color azul
cap = cv2.VideoCapture(0)
while(1):

    # Take each frame
    _, frame = cap.read()

    # Convert BGR to HSV
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    # define range of blue color in HSV
    lower_blue = np.array([110,50,50])
    upper_blue = np.array([130,255,255])

    # Threshold the HSV image to get only blue colors
    mask = cv2.inRange(hsv, lower_blue, upper_blue)

    # Bitwise-AND mask and original image
    res = cv2.bitwise_and(frame,frame, mask= mask)

    cv2.imshow('frame',frame)
    cv2.imshow('mask',mask)
    cv2.imshow('res',res)
    k = cv2.waitKey(5) & 0xFF
    if k == 27:
        break

cv2.destroyAllWindows()
'''
