import secrets
import string

def create_password():
    password = ""
    char_list = list(string.ascii_letters)
    n_chars = secrets.randbelow(20) + 10 # minim 10 caractere
    for _ in range(n_chars):
        password += secrets.choice(char_list)
        password += secrets.choice(['.', '!', '$', '@', ''])
    password += secrets.choice(list(string.ascii_lowercase))
    password += secrets.choice(list(string.ascii_uppercase))
    password += secrets.choice(['.', '!', '$', '@', ''])
    return password


print(f'Parola generata: {create_password()}') # aceasta functionalitate poate fi folosita intr un password manager, sau chiar aplicatia sa-ti sugereze o parola
print(f'Url generat: {secrets.token_urlsafe(32)}') # poate fi folosit cand aplicatia iti genereaza un link care ar trebui sa fie personal si sa nu fie usor accesibil de oricine
print(f'Token generat: {secrets.token_hex(32)}') # ar putea fi bun drept cheie de criptare

secventa1 = "Mesaj super secret"
secventa2 = "Mesaj deloc secret"

print(f'Sunt mesajele la fel ? {secrets.compare_digest(secventa1, secventa2)}')

key_size = secrets.randbelow(256) + 800
key = secrets.randbits(key_size)
print(f'Cheia fluida binara este: {bin(key)}')

import bcrypt

def hash_password(password):
    salt = bcrypt.gensalt()
    hashed_password = bcrypt.hashpw(password.encode(), salt)
    return hashed_password.decode(), salt

def check_password(password, hashed_password):
    return bcrypt.checkpw(password.encode(), hashed_password.encode())

print(hash_password('salutare'))
hashed_password, salt = hash_password('salutre')
print(f'Parola hashed:{hashed_password}')
print(f'Verificare parola: {check_password('salutare', hash_password)}')