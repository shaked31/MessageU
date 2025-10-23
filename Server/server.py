import sqlite3

def main():
    conn = sqlite3.connect('defensive.db')
    cur = conn.cursor()

    cur.execute("""
        CREATE TABLE IF NOT EXISTS clients(
            ID BLOB(16) PRIMARY KEY,
            UserName NOT NULL CHECK(length(UserName) <= 254),
            PublicKey BLOB(160) NOT NULL,
            LastSeen DATETIME
    )""")

    cur.execute("""
        CREATE TABLE IF NOT EXISTS messages(
            ID BLOB(4),
            UserName NOT NULL CHECK(length(UserName) <= 254),
            PublicKey BLOB(160) NOT NULL,
            LastSeen DATETIME
    )""")