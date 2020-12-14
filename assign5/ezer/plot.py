import numpy as np

faults, frames = np.loadtxt("outputFIFO.txt", delimiter=',', usercols=(1,2), unpack=True)

print faults, frames
