import uhd
import numpy as np
# import benchmark_rate
import os
import matplotlib.pyplot as plt

##### User-Defined Params

# System
center_freq = 2e9	#Hz
rx_sample_rate = 10e6	#Samples/Second
tx_sample_rate = 10e6	#Samples/Second
tx_gain = 50		# Tx Front End Gain (Not Physically Meaningful)
rx_gain = 40		# Rx Front End Gain (Not Physically Meaningful)

# Waveform
B = 0.6			# Percent Bandwidth (relative to TX sample rate)
Tp_r = .1e-3		# Requested Transmit Pulse Duration (seconds)
Tpri_r = 1e-3		# Requested Transmit PRI (seconds)
Tcpi_r = 10e-3		# Requested Transmit CPI Duration (seconds)

##### Derivative Parameters

# Actual Waveform Parameters
Np_a = np.floor(Tp_r*tx_sample_rate)
Tp_a = Np_a/tx_sample_rate
Npri_a = np.floor(Tpri_r*tx_sample_rate)
Tpri_a = Npri_a/tx_sample_rate

P = np.floor(Tcpi_r/Tpri_a)
Ncpi_a = Npri_a*P
Tcpi_a = Ncpi_a/tx_sample_rate

# Create one pulse
t = np.linspace(0,Np_a-1,num=Np_a)
s = np.exp(1j*2*np.pi*(-B/2*t+0.5*B/Np_a*t*t))

# Create Transmit Sequence Matrix, One PRI per Row
# (GROSS: Python forces you to use row vectors)
S = np.zeros((np.int64(P), np.int64(Npri_a)),  dtype=np.complex64)
S[:, 0:np.int64(Np_a)] = np.tile(s,(np.int64(P),1))

# Create the Transmit Sequence
s_tx = np.reshape(S, (S.size,1))

#### Plot

#Sfft = np.fft.fft(S, 2*S.shape[0], axis=0)
#plt.imshow(10*np.log10(np.square(np.abs(Sfft))))
#plt.show()

plt.plot(np.imag(s_tx))
plt.show()

# os.system("python3 benchmark_rate.py --tx_rate " tx_sample_rate " --rx_rate " rx_sample_rate)
os.system("python3 benchmark_rate.py --tx_rate 10e6 --rx_rate 10e6")


# with open("benchmark_rate.py") as file:
#     exec(file.read())