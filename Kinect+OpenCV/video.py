FFMPEG_BIN = "ffplay"

import subprocess as sp
import os 	

def playVideo(video):
	command = [ FFMPEG_BIN,video,'-autoexit','-fs']         
	pipe = sp.Popen(command, stdout = sp.PIPE, bufsize=10**8, stderr = sp.PIPE)
	pipe.wait()

def playPrincipal():
	#sp.call(["ffplay", "-an", "-autoexit","videos/01-bienvenida.webm"])
	command = [ FFMPEG_BIN,"videos/01-bienvenida.webm","-autoexit","-an"]
	pipe2 = sp.Popen(command, stdout = sp.PIPE, bufsize=10**8, stderr = sp.PIPE)

	playPrincipal()