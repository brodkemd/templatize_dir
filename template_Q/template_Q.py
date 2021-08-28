from qiskit import *
from qiskit.tools.visualization import plot_bloch_multivector
from qiskit.tools.visualization import plot_histogram
import matplotlib.pyplot as plt

n = 1

qc = QuantumCircuit(Qbits n, Cbits n)

print(qc.draw())