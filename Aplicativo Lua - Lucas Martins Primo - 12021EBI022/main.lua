require "physics"
physics.start()
--physics.setDrawMode("hybrid")
require "vida"


fundo = vida.ajustarFundo("quadra.jpg")
function start(contagem)

--------- objetos-------

jogador = display.newImage("jogador.png",180,1050)
physics.addBody(jogador,"static",{outline=graphics.newOutline (2,"jogador.png"),friction = 0.3})

chao = display.newImage("chão.png",180,1080)
physics.addBody(chao,"static",{outline=graphics.newOutline (2,"chão.png"),friction = 0.3})

--Cesta de basquete---
basketFundo  = vida.plotaFiguraXY("basketFundo.png",432,400)
basketFrente = vida.plotaFiguraXY("basketFrente.png",432,400)
tabela = vida.plotaFiguraXY("tabela.png",432,400)
physics.addBody(tabela,"static",{outline=graphics.newOutline (2,"tabela.png")})
cestaEsquerda = vida.plotaFiguraXY("cestaEsquerda.png",432,400)
physics.addBody(cestaEsquerda,"static",{outline=graphics.newOutline (2,"cestaEsquerda.png")})
cestaDireita = vida.plotaFiguraXY("cestaDireita.png",432,400)
physics.addBody(cestaDireita,"static",{outline=graphics.newOutline (2,"cestaDireita.png")})

----------------------

-- AÇÕES
somSensor = audio.loadSound("ponto.mp3")
sensordospontos = vida.criarSensorDePontos (475,530,200,10,0,0,somSensor)
marcadorDePontos = vida.marcarPontos(3)

bolaArremesso = vida.criarBolaDeArremesso(30,400,100,"bola.png",230,-30,60,0.2,0.1,20,0.8,1,1,1)

--bola = display.newImage("bola.png",225,890)
--physics.addBody(bola,"dynamic",{outline=graphics.newOutline (2,"bola.png"),friction = 0.3, radius = 50, density = 5, bounce = .1})
--vida.arremessar(bola,7,1,1,1,1)

-- REINICIAR
botaoRestart = vida.restart("botao.png",600,100,{marcadorDePontos,sensordospontos,cestaDireita,cestaEsquerda,basketFundo,basketFrente,tabela,jogador,chao,bolaArremesso},{timersVida})

end
start()