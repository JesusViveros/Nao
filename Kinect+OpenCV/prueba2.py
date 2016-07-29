# coding: utf-8
import freenect
import cv2
import numpy
import sys
import video as v
import math

threshold = 80
current_depth = 830
prev = None

cv2.namedWindow('Original')
cv2.namedWindow('Mapa')
tilt = 15

def show_depth(dev, data, timestamp):
    global threshold
    global current_depth
    global prev
    
    actual = data

    if prev is None:
        prev = numpy.array(actual)

    source = (actual + prev) / 2

    prev = actual

    depth = 255 * numpy.logical_and(
            source >= current_depth - threshold,
            source <= current_depth + threshold)

    source += 1
    source >>= 3
    depth = depth.astype(numpy.uint8)
    source = source.astype(numpy.uint8)
    cv2.imshow('Mapa', depth)

    draw_convex_hull(depth, source)

    if cv2.waitKey(10) == 27:
        sys.exit()


def draw_convex_hull(a, original):
    original = cv2.cvtColor(original, cv2.COLOR_GRAY2BGR)

    ret, b = cv2.threshold(a, 255, 255, cv2.THRESH_BINARY)

    contornos, jerarquia = cv2.findContours(a,cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_SIMPLE)

    for n, cnt in enumerate(contornos):
        hull = cv2.convexHull(cnt)
        foo = cv2.convexHull(cnt, returnPoints=False)
        cv2.drawContours(original, contornos, n, (0, 35, 245))

        if len(cnt) > 3 and len(foo) > 2:
            defectos = cv2.convexityDefects(cnt, foo)
            if defectos is not None:
                defectos = defectos.reshape(-1, 4)
                puntos = cnt.reshape(-1, 2)
                for d in defectos:
                    if d[3] > 20:
                        cv2.circle(original, tuple(puntos[d[0]]), 5, (255, 255, 0), 2)
                        cv2.circle(original, tuple(puntos[d[1]]), 5, (255, 255, 0), 2)
                        cv2.circle(original, tuple(puntos[d[2]]), 5, (0, 0, 255), 2)

        lista = numpy.reshape(hull, (1, -1, 2))
        cv2.polylines(original, lista, True, (0, 255, 0), 3)
        center, radius = cv2.minEnclosingCircle(cnt)
        center = tuple(map(int, center))
        radius = int(radius)
        cv2.circle(original, center, radius, (255, 0, 0), 3)
    
        # 			 0        1        2        3        4
        points = [(120,60),(220,60),(320,60),(420,60),(520,60),
        #             5        6         7         8         9
        		  (80,150),(220,150),(320,150),(420,150),(560,150),
        #             10       11        12        13        14
        		  (80,240),(220,240),(320,240),(420,240),(560,240),
        #             15       16        17        18        19
        		  (80,330),(220,330),(320,330),(420,330),(560,330),
        #             20       21        22        23        24
        		  (120,460),(220,420),(320,420),(420,420),(520,460),
       	#			puntos extras
        		  (170,150),(220,30),(420,30),(150,120),(190,180)]

        for i in range(0,30):
        	cv2.circle(original,points[i],4,[255,255,0],2)

        A = int(center[0])
        B = int(center[1])
        x1 = int(points[0][0])
        y1 = int(points[0][1])
        x2 = int(points[4][0])
        y2 = int(points[4][1])
        x3 = int(points[20][0])
        y3 = int(points[20][1])
        x4 = int(points[24][0])
        y4 = int(points[24][1])
        x5 = int(points[1][0])
        y5 = int(points[1][1])
        x6 = int(points[3][0])
        y6 = int(points[3][1])
        x7 = int(points[21][0])
        y7 = int(points[21][1])
        x8 = int(points[23][0])
        y8 = int(points[23][1])

        dist1 = math.sqrt((A-x1)**2 + (B-y1)**2) #distancia al punto 0
        dist2 = math.sqrt((A-x2)**2 + (B-y2)**2) #distancia al punto 4
        dist3 = math.sqrt((A-x3)**2 + (B-y3)**2) #distancia al punto 20
        dist4 = math.sqrt((A-x4)**2 + (B-y4)**2) #distancia al punto 24
        dist5 = math.sqrt((A-x5)**2 + (B-y5)**2)
        dist6 = math.sqrt((A-x6)**2 + (B-y6)**2)
        dist7 = math.sqrt((A-x7)**2 + (B-y7)**2)
        dist8 = math.sqrt((A-x8)**2 + (B-y8)**2)

        punto0  = cv2.pointPolygonTest(hull,points[0], True)
        punto1  = cv2.pointPolygonTest(hull,points[1], True)
        punto2  = cv2.pointPolygonTest(hull,points[2], True)
        punto3  = cv2.pointPolygonTest(hull,points[3], True)
        punto4  = cv2.pointPolygonTest(hull,points[4], True)
        punto5  = cv2.pointPolygonTest(hull,points[5], True)
        punto6  = cv2.pointPolygonTest(hull,points[6], True)
        punto7  = cv2.pointPolygonTest(hull,points[7], True)
        punto8  = cv2.pointPolygonTest(hull,points[8], True)
        punto9  = cv2.pointPolygonTest(hull,points[9], True)
        punto10 = cv2.pointPolygonTest(hull,points[10], True)
        punto11 = cv2.pointPolygonTest(hull,points[11], True)
        punto12 = cv2.pointPolygonTest(hull,points[12], True)
        punto13 = cv2.pointPolygonTest(hull,points[13], True)
        punto14 = cv2.pointPolygonTest(hull,points[14], True)
        punto15 = cv2.pointPolygonTest(hull,points[15], True)
        punto16 = cv2.pointPolygonTest(hull,points[16], True)
        punto17 = cv2.pointPolygonTest(hull,points[17], True)
        punto18 = cv2.pointPolygonTest(hull,points[18], True)
        punto19 = cv2.pointPolygonTest(hull,points[19], True)
        punto20 = cv2.pointPolygonTest(hull,points[20], True)
        punto21 = cv2.pointPolygonTest(hull,points[21], True)
        punto22 = cv2.pointPolygonTest(hull,points[22], True)
        punto23 = cv2.pointPolygonTest(hull,points[23], True)
        punto24 = cv2.pointPolygonTest(hull,points[24], True)
        puntoPuno = cv2.pointPolygonTest(hull,points[25], True)
        puntoR1 = cv2.pointPolygonTest(hull,points[26], True)
        puntoR2 = cv2.pointPolygonTest(hull,points[27], True)
        puntoPuno2 = cv2.pointPolygonTest(hull,points[28], True)
        puntoPuno3 = cv2.pointPolygonTest(hull,points[29], True)
        #brazos abiertos
        if ((radius > dist1) and (radius > dist3)):
	        if ((punto10 > 0.0) and (punto14 > 0.0)):
        		print "Nao"
#        		v.playVideo("videos/buenos/nao.mpg")
        		break
        
        elif (( radius < dist1 ) or ( radius < dist2 )) and (( radius < dist4 ) and ( radius < dist3 )):
        	if ( (radius >= dist7) and (radius >= dist8)):
		        if((punto10 < 0.0) and (punto14 < 0.0) and puntoR1 > 0.0):
			        #saludo
			        if ((puntoPuno > 0.0) or (puntoPuno2 > 0.0) or (puntoPuno3 > 0.0)):
		        		print "Bienvenida"
#		        		v.playVideo("videos/buenos/bienvenida.mpg")
		        		break
		        	if ((puntoR1 > 0.0) or (puntoR2 > 0.0)):
		        		print "Robots"
#		        		v.playVideo("videos/buenos/moviles.mpg")
		        		break

		elif ( (radius > dist1) and (radius < dist2) and (radius > dist3)and (radius < dist4)):
			
			if ((punto8 > 0.0) and (punto13 > 0.0) and (punto10 < 0.0) and (punto14 > 0.0) ):
				print "redes"
#				v.playVideo("videos/buenos/rna.mpg")
				break
			
			if ((punto8 < 0.0) and (punto14 < 0.0) and (punto10 > 0.0) and (punto11 > 0.0)):
				print "Banda"
#				v.playVideo("videos/buenos/banda.mpg")
				break
    cv2.imshow('Original', original)

    #cv2.createTrackbar('threshold', 'Original', threshold,     500,  change_threshold)
    #cv2.createTrackbar('depth',     'Original', current_depth, 2048, change_depth)
    #cv2.createTrackbar('tilt', 'Original', 0, 30, change_tilt)

def main(dev, ctx):
    freenect.set_tilt_degs(dev, tilt)

if __name__ == '__main__':
	freenect.runloop(depth=show_depth, body=main)

