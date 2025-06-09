import serial

class ReadLine:
    def __init__(self, s):
        self.buf = bytearray()
        self.s = s

    def readline(self):
        i = self.buf.find(b"\n")
        if i >= 0:
            r = self.buf[:i+1]
            self.buf = self.buf[i+1:]
            return r.decode("utf-8")
        while True:
            i = max(1, min(2048, self.s.in_waiting))
            data = self.s.read(i)
            i = data.find(b"\n")
            if i >= 0:
                r = self.buf + data[:i+1]
                self.buf[0:] = data[i+1:]
                return r.decode("utf-8")
            else:
                self.buf.extend(data)

ser = serial.Serial('COM7', 115200)
rl = ReadLine(ser)
printed = False
while not printed:
    line = rl.readline()
    print("Received:", line)
    
    #print_temp = str2list(line)
    #if print_temp != False:
        #print(print_temp)
        #plot_dots(print_temp)
    #printed = True