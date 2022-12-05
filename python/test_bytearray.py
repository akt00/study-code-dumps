# bytearray

msg: str = "hello"
byte_msg = bytearray(msg, 'utf-8')

print(byte_msg)
print(byte_msg.__sizeof__())
