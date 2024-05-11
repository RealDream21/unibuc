import matplotlib.pyplot as plt

def cross_product(p0, pi, q):
    A = [pi[0] - p0[0], pi[1] - p0[1]]
    B = [q[0] - p0[0], q[1] - p0[1]]
    return A[0]*B[1] - B[0]*A[1]

def stangaSauDreapta(xp, yp, xq, yq, xr, yr):
    det = xq * yr + xr * yp + xp * yq - xq * yp - xr * yq - xp * yr
    return det

def rezolva(punct_test):
    xp, yp = convex_points[-1]
    xq, yq = convex_points[0]
    xr, yr = punct_test

    if stangaSauDreapta(xp, yp, xq, yq, xr, yr) == 0:
        return "BOUNDARY"
    if stangaSauDreapta(xp, yp, xq, yq, xr, yr) < 0:
        return "OUTSIDE"
    
    for i in range(len(convex_points) - 1):
        xp, yp = convex_points[i]
        xq, yq = convex_points[i + 1]
        xr, yr = punct_test

        if stangaSauDreapta(xp, yp, xq, yq, xr, yr) == 0:
            return "BOUNDARY"
        if stangaSauDreapta(xp, yp, xq, yq, xr, yr) < 0:
            return "OUTSIDE"
    
    return "INSIDE"

# Sample points
points = [(1, 2), (3, 4), (5, 6), (7, 8), (2, 7), (6, 2), (9, 5), (4, 9), (8, 1)]

# Compute convex hull
convex_points = [(1, 2), (3, 4), (7, 8), (9, 5), (4, 9), (8, 1)]

# Plot convex hull
plt.figure()
convex_hull = plt.Polygon(convex_points, closed=True, edgecolor='r', fill=False)
plt.gca().add_patch(convex_hull)

# Plot points and label them as inside or outside the convex hull
for point in points:
    label = rezolva(point)
    color = 'r' if label == "INSIDE" else 'y'
    plt.plot(point[0], point[1], marker='o', markersize=8, color=color)

plt.xlabel('X')
plt.ylabel('Y')
plt.title('Convex Hull with Inside/Outside Points')
plt.grid(True)
plt.show()
