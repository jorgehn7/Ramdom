'''
sudo pip install Flask
sudo apt-get install npm
npm install -g localtunnel

#Run this script

on a new terminal window:
lt --port 5000

#OPEN you imagination
'''

from flask import Flask
app = Flask(__name__)

@app.route('/')
def hello_world():
    return 'Hello World!'

if __name__ == '__main__':
    app.run()

