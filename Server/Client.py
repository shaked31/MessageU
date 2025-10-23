import time

class Client:
    def __init__(self, id, username: str, public_key, last_seen):
        self.id = id
        self.username = username
        self.public_key = public_key
        self.last_seen = last_seen
