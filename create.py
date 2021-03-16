import math
import random



# DECAGONAL PRISM
print("DECAGONAL PRISM")
print()
n = 10
r = 0.5
verts = []
for i in range(n): 
	
	x = r * math.cos(2 * math.pi * i / n)
	y = r * math.sin(2 * math.pi * i / n)
	verts.append([x,y,0.5])
	verts.append([x,y,-0.5])

print("Vertices for GL:")

for v in range(n):

	r,g,b = [random.random(), random.random(), random.random()]
	print("%.3ff, %.3ff, %.3ff,   %.3ff, %.3ff, %.3ff," % (verts[2*v-2][0],verts[2*v-2][1],verts[2*v-2][2], r,g,b))
	print("%.3ff, %.3ff, %.3ff,   %.3ff, %.3ff, %.3ff," % (verts[2*v-1][0],verts[2*v-1][1],verts[2*v-1][2], r,g,b))
	print("%.3ff, %.3ff, %.3ff,   %.3ff, %.3ff, %.3ff," % (verts[2*v][0],verts[2*v][1],verts[2*v][2], r,g,b))
	print()

	print("%.3ff, %.3ff, %.3ff,   %.3ff, %.3ff, %.3ff," % (verts[2*v-1][0],verts[2*v-1][1],verts[2*v-1][2], r,g,b))
	print("%.3ff, %.3ff, %.3ff,   %.3ff, %.3ff, %.3ff," % (verts[2*v][0],verts[2*v][1],verts[2*v][2], r,g,b))
	print("%.3ff, %.3ff, %.3ff,   %.3ff, %.3ff, %.3ff," % (verts[2*v+1][0],verts[2*v+1][1],verts[2*v+1][2], r,g,b))
	print()


tr,tg,tb = [random.random(), random.random(), random.random()]
for v in range(1,n-1):
	print("%.3ff, %.3ff, %.3ff,   %.3ff, %.3ff, %.3ff," % (verts[0][0],verts[0][1],verts[0][2], tr,tg,tb))
	print("%.3ff, %.3ff, %.3ff,   %.3ff, %.3ff, %.3ff," % (verts[2*v][0],verts[2*v][1],verts[2*v][2], tr,tg,tb))
	print("%.3ff, %.3ff, %.3ff,   %.3ff, %.3ff, %.3ff," % (verts[2*v+2][0],verts[2*v+2][1],verts[2*v+2][2], tr,tg,tb))
	print()

br,bg,bb = [random.random(), random.random(), random.random()]
for v in range(1,n-1):
	print("%.3ff, %.3ff, %.3ff,   %.3ff, %.3ff, %.3ff," % (verts[1][0],verts[1][1],verts[1][2], br,bg,bb))
	print("%.3ff, %.3ff, %.3ff,   %.3ff, %.3ff, %.3ff," % (verts[2*v+1][0],verts[2*v+1][1],verts[2*v+1][2], br,bg,bb))
	print("%.3ff, %.3ff, %.3ff,   %.3ff, %.3ff, %.3ff," % (verts[2*v+3][0],verts[2*v+3][1],verts[2*v+3][2], br,bg,bb))
	print()

print()
print()



# HEXAGONAL DIPYRAMID
print("HEXAGONAL DIPYRAMID")
n = 6
r = 0.5
verts = []
for i in range(n): 
	
	x = r * math.cos(2 * math.pi * i / n)
	y = r * math.sin(2 * math.pi * i / n)
	verts.append([x,y,0])

top = [0,0,0.5]
bottom = [0,0,-0.5]

print("Vertices for GL:")
for v in range(n):

	r,g,b = [random.random(), random.random(), random.random()]
	print("%.3ff, %.3ff, %.3ff,   %.3ff, %.3ff, %.3ff," % (verts[v-1][0],verts[v-1][1],verts[v-1][2], r,g,b))
	print("%.3ff, %.3ff, %.3ff,   %.3ff, %.3ff, %.3ff," % (verts[v][0],verts[v][1],verts[v][2], r,g,b))
	print("%.3ff, %.3ff, %.3ff,   %.3ff, %.3ff, %.3ff," % (top[0],top[1],top[2], r,g,b))
	print()

	r,g,b = [random.random(), random.random(), random.random()]
	print("%.3ff, %.3ff, %.3ff,   %.3ff, %.3ff, %.3ff," % (verts[v-1][0],verts[v-1][1],verts[v-1][2], r,g,b))
	print("%.3ff, %.3ff, %.3ff,   %.3ff, %.3ff, %.3ff," % (verts[v][0],verts[v][1],verts[v][2], r,g,b))
	print("%.3ff, %.3ff, %.3ff,   %.3ff, %.3ff, %.3ff," % (bottom[0],bottom[1],bottom[2], r,g,b))
	print()

print()
print()








# UNDECAGONAL PYRAMID
print("UNDECAGONAL PYRAMID")
print()
n = 11
r = 0.5
verts = []
for i in range(n): 
	
	x = r * math.cos(2 * math.pi * i / n)
	y = r * math.sin(2 * math.pi * i / n)
	verts.append([x,y,0])
top = [0,0,0.5]

print("Vertices for GL:")
for v in range(n):

	r,g,b = [random.random(), random.random(), random.random()]
	print("%.3ff, %.3ff, %.3ff,   %.3ff, %.3ff, %.3ff," % (verts[v-1][0],verts[v-1][1],verts[v-1][2], r,g,b))
	print("%.3ff, %.3ff, %.3ff,   %.3ff, %.3ff, %.3ff," % (verts[v][0],verts[v][1],verts[v][2], r,g,b))
	print("%.3ff, %.3ff, %.3ff,   %.3ff, %.3ff, %.3ff," % (top[0],top[1],top[2], r,g,b))
	print()

r,g,b = [random.random(), random.random(), random.random()]
for v in range(1,n-1):
	print("%.3ff, %.3ff, %.3ff,   %.3ff, %.3ff, %.3ff," % (verts[0][0],verts[0][1],verts[0][2], r,g,b))
	print("%.3ff, %.3ff, %.3ff,   %.3ff, %.3ff, %.3ff," % (verts[v][0],verts[v][1],verts[v][2], r,g,b))
	print("%.3ff, %.3ff, %.3ff,   %.3ff, %.3ff, %.3ff," % (verts[v+1][0],verts[v+1][1],verts[v+1][2], r,g,b))
	print()


print()
print()
