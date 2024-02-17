import socket
import pyautogui

HOST = '0.0.0.0'  # Listening on all IP addresses
PORT = 1234  # The port on which the server is listening

def main(conn):
    print('Connected by', conn.getpeername())
    while True:
        data = conn.recv(1024)
        if not data:
            print("The connection has been closed.")
            break
        print("Received:", data.decode())
        pyautogui.hotkey('alt', 'tab')
def start_server():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.bind((HOST, PORT))
        s.listen()
        print("listens on port:",PORT)
        while True:
            conn, addr = s.accept()
            with conn:
                main(conn)

if __name__ == "__main__":
    start_server()
