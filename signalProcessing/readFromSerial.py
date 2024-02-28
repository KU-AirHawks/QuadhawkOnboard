import serial

def serialRead(port, baudrate=9600):
    ser = serial.Serial(port, baudrate)
    
    try:
        while True:
            if ser.in_waiting >0:
                data = ser.readline().decode().strip()
                print("Received:", data)
    except KeyboardInterrupt:
        print("Closing...")
        ser.close()
        
if __name__ == "__main__":
    serial_port = "dev/ttyUSB4"  # Replace with serial port
    serialRead(serial_port)