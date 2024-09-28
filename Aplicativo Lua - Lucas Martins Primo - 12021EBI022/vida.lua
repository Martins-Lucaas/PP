module(... , package.seeall)
function vidaInsideFiguraSt(figura)
--St = padrão ->  
-- density = 1                [1.0 = água:  mais leves (boia na água) <1, mais pesados (afunda na água) >1]
-- friction(atrito>0) = 0.3   [0.0 = sem fricção, 1.0 = fricção forte]
-- bounce (restitution) = 0.2 [0.0 = sem bounce , >=1.0, quica eternamente (sem perda)] 
 contorno =  {outline = graphics.newOutline( 2, figura )}
 return contorno
end
function plotaFiguraXY(figura, x,y)
 figuraTeste = display.newImage (figura,(2*x)+5000,(2*y)+5000)
 largura = figuraTeste.width
 altura  = figuraTeste.height
 return display.newImage(figura,x+(largura/2),y+(altura/2))
end 

function objetosCaindoConta(bolaImagem,figuraFrente,posXF,posYF,numero,tempo)
	local Grupo = display.newGroup()
	local bola = {}
	local i = 1
	local jaAdicionou = false
	W = display.contentWidth
	H = display.contentHeight
	function jogarBolas()
		posX = math.random(55,W-55)
		bola[i] = display.newImageRect(bolaImagem,110,110)
		bola[i].x = posX
		bola[i].y = -80
		physics.addBody(bola[i],"dynamic",{density = 5,bounce = 0.3,radius = 55,friction = 1})
		if jaAdicionou == false then
			sextaDeBasqueteFrente = plotaFiguraXY(figuraFrente,posXF,posYF)
		end
		jaAdicionou = true
		Grupo:insert(bola[i])
		Grupo:insert(sextaDeBasqueteFrente)
		i = i+1
		return
	end
	local timerBolas = timer.performWithDelay(tempo*1000,jogarBolas,numero)
	return Grupo,timerBolas
end



function objetosCaindo(objetoImagem,quantidade,tempo)
local objeto = {}
local i = 1
	W = display.contentWidth
	H = display.contentHeight
	function jogarObjetos()
		posX = math.random(15,W-15)
		objeto[i] = display.newImageRect(objetoImagem,110,110)
		objeto.x = posX
		objeto.y = -80
		physics.addBody(objeto,"dynamic",{density = 1,bounce = 0.3,radius = 55,friction = 1})
		i = i+1
	end
	timer.performWithDelay(tempo*1000,jogarObjetos,quantidade)
	return objeto
end
function somAoColidir(objeto,somObjeto)
	function somAoColidirAux(e)
		if e.phase == "began" then
			audio.play(somObjeto)
		end
	end
	objeto:addEventListener("collision",somAoColidirAux)
end

--[[
function marcarPontos(sensorMarcador)
	local Grupao = display.newGroup()
	texto = display.newText("Pontos: 0",120,100,system.nativeFont,50)
	texto:setFillColor(0.5,0.5,1)
	pontos = 0
	function marcarPontosAux(e)
		temSensorPontos = true
		if e.phase == "ended" then
			pontos = pontos + 1
			print(pontos)
			texto.text = "Pontos: " .. pontos
		end
	end
	if temSensorPontos == nil or temSensorPontos == false then
		sensorMarcador:addEventListener("collision",marcarPontosAux)
	end
	Grupao:insert(texto)
	return Grupao
end
function sensorPontos(x,y,comp,alt,ang,inv,som)        --,r,g,b) -- r, g e b - 0.0->1.0
	local Grupo = display.newGroup()
   sensor = display.newRect(x+(comp/2),y+(alt/2),comp,alt)
   --sensor:setFillColor(r,g,b)
   sensor.rotation = ang 
   sensor.alpha = inv -- 0-1, onde zero  é transparente e  1 sem transparência
   physics.addBody(sensor,"static",{isSensor = true})
   somAoColidir(sensor,som)
   Grupo:insert(marcarPontos(sensor))
   return Grupo
end 
]]
function marcarPontos(maxPlacar)
	local Grupo = display.newGroup()
	_textoPontos = display.newText("Pontos: 0",120,100,system.nativeFont,50)
	_textoPontos:setFillColor(0.5,0.5,1)
	_contagemPontos = 0
	function marcarAux()
		if maxPlacar then
			if _contagemPontos >= maxPlacar then 
				gameOver = display.newText(Grupo,"GAME OVER",display.contentWidth/2,display.contentHeight/2,system.nativeFont,80)
				gameOver:setFillColor(1,0.5,1)
			end
		end
		temMarcadorPontos = true
		_textoPontos.text = "Pontos: ".._contagemPontos
	end
	if temMarcadorPontos == nil or temMarcadorPontos == false then
		Runtime:addEventListener("enterFrame",marcarAux)
	end
	Grupo:insert(_textoPontos)
	return Grupo
end

function criarSensorDePontos(posX,posY,comp,alt,rotacao,nAlpha,som)
	local Grupo = display.newGroup()
	--sensor = display.newRect(posX,posY,larg,alt)
	sensor = display.newRect(posX+(comp/2),posY+(alt/2),comp,alt)
	sensor.rotation = rotacao
	sensor.alpha = nAlpha
	physics.addBody(sensor,"static",{isSensor = true})
	function marcarPontosAux(e)
		if e.phase == "ended" then
			if _contagemPontos then
				_contagemPontos = _contagemPontos +1
			end
		end
	end
	somAoColidir(sensor,som)
	sensor:addEventListener("collision",marcarPontosAux)
	Grupo:insert(sensor)
	return Grupo
end

function empurra(w,h)
	function empurrarObjetosDinamicos(event)
		if event.phase == "began" then
			toque = display.newRect(event.x,event.y,w,h)
			physics.addBody(toque,"kinematic",{friction = .5,density = .2, bounce = 1})
			display.getCurrentStage():setFocus(event.target, event.id);
			--toque.tipo = "personagem"
		end
		if event.phase == "moved" or event.phase == "stationary" then
			toque.x = event.x
			toque.y = event.y
		end
		if event.phase == "ended" then
			toque:removeSelf()
			display.getCurrentStage():setFocus();
		end
	end
	if temEmpurra == false or temEmpurra == nil then
		Runtime:addEventListener("touch",empurrarObjetosDinamicos)
		temEmpurra = true
	end
end
function destroiEmpurra(w,h)
	function empurrarObjetosDinamicos(event)
		if event.phase == "began" then
			toque = display.newRect(event.x,event.y,w,h)
			physics.addBody(toque,"kinematic",{friction = .5,density = .2, bounce = 1})
			display.getCurrentStage():setFocus(event.target, event.id);
			toque.tipo = "personagem"
		end
		if event.phase == "moved" or event.phase == "stationary" then
			toque.x = event.x
			toque.y = event.y
		end
		if event.phase == "ended" then
			toque:removeSelf()
			display.getCurrentStage():setFocus();
		end
	end
	if temEmpurra == false or temEmpurra == nil then
		Runtime:addEventListener("touch",empurrarObjetosDinamicos)
		temEmpurra = true
	end
end
function restart(imagemBotao,posX,posY,vetorImagens,vetorTimers)
	botaodeRestart = display.newImage(imagemBotao,posX,posY)
	function restartarOApp()
		if #vetorImagens > 0 then
			for i=1, #vetorImagens do
				--display.remove(vetorImagens[i])
				vetorImagens[i]:removeSelf()
				vetorImagens[i] = nil
			end
		end
		if #vetorTimers > 0 then
			for i=1,#vetorTimers do
				timer.cancel(vetorTimers[i])
				vetorTimers[i] = nil
			end
		end
		botaodeRestart:removeSelf()
		timer.performWithDelay(10,function() start() end,1)

	end
	botaodeRestart:addEventListener("tap",restartarOApp)
	return botaodeRestart
end


function objetosCaindoInimigo(bolaImagem,figuraFrente,posXF,posYF,numero,tempo,som,modificador)
Grupo = display.newGroup()
local bola = {}
local i = 1
local jaAdicionou = false
	W = display.contentWidth
	H = display.contentHeight
	function jogarBolas()
		posX = math.random(55,W-55)
		bola[i] = display.newImageRect(bolaImagem,110,110)
		bola[i].x = posX
		bola[i].y = -80
		physics.addBody(bola[i],"dynamic",{density = 5,bounce = 0.3,radius = 55,friction = 1})
		inimigoSimplesComSom(bola[i],som,modificador)
		if jaAdicionou == false then
			sextaDeBasqueteFrente = plotaFiguraXY(figuraFrente,posXF,posYF)
		end
		jaAdicionou = true
		Grupo:insert(bola[i])
		Grupo:insert(sextaDeBasqueteFrente)
		i = i+1
		return
	end
	local timerBolas = timer.performWithDelay(tempo*1000,jogarBolas,numero)
	return Grupo,timerBolas
end


----------------------------
--------------
--------------
--------------
--------------
--------------
--------------
--------------
--------------
--------------
--------------
--------------
--------------
--------------
--------------
--------------
----------------------------




function ajustarFundo(fundoVar)
	local fundo = display.newImageRect(fundoVar,display.contentWidth,display.contentHeight)
	fundo.x = display.contentWidth/2; fundo.y = display.contentHeight/2
	return fundo
end
function criarAnimacaoGeral(k,imagem,numeroDeFrames,tempoDeAnimacao,contageLoop,caracteristica)
	objeto = display.newImage(imagem,-700,400)
	larguraObjeto = objeto.width
	alturaObjeto = objeto.height
	objeto:removeSelf()
	print(larguraObjeto)
	print(alturaObjeto)
	---------------------------------------------------------------------------------------------
	---------------------------------------------------------------------------------------------
		bola = {}
		sheetInfo = {}
		bolaSheet = {}
		sequenciaInfo = {}

		sheetInfo[k] = {
		  width = larguraObjeto/numeroDeFrames,
		  height = alturaObjeto,
		  numFrames = numeroDeFrames
		}

		bolaSheet[k] = graphics.newImageSheet(imagem,sheetInfo[k])

		sequenciaInfo[k] = 
		{
			{
				name = "CorridaNormal",
				start = 1,
				count = numeroDeFrames,
				time = tempoDeAnimacao,
				loopCount = contageLoop,
				loopDirection = caracteristica,
			}
		}
	bola = display.newSprite(bolaSheet[k],sequenciaInfo[k]) 
	bola:setSequence("piscar")
	bola:play()
	return bola
end
function criarAnimacaoDePiscar(k,imagem,numeroDeFrames,tempoDeAnimacao,caracteristica,frequenciaDePiscarSegundos)
	
	local bola = criarAnimacaoGeral(k,imagem,numeroDeFrames,tempoDeAnimacao,1,caracteristica)
	function piscarNovamente()
		local randomico = math.random(0,5)
		if randomico < 4 then
			bola:play()
		end
	end
	timer.performWithDelay(frequenciaDePiscarSegundos*1000,piscarNovamente,-1)
	return bola
end

function criarLinha(objeto,e,r,g,b,a)
	if(e.phase == "began")then
		display.getCurrentStage():setFocus(objeto)
		myline = nil
	elseif (e.phase == "moved")then
		if myline then
			myline.parent:remove(myline)
		end
		myline = display.newLine(objeto.x,objeto.y,e.x,e.y)
		myline:setColor(r,g,b)
		myline.width = 5
		myline.alpha = a
	elseif (e.phase == "ended")then
		if myline then
			myline.parent:remove(myline)
		end
		display.getCurrentStage():setFocus(nil)
	end
end

function arremessar(objeto,forca,r,g,b,a)
	
	function arrastaObjeto(e)
		vida.criarLinha(objeto,e,r,g,b,a)

		if(e.phase == "began")then

			display.getCurrentStage():setFocus(objeto)

		elseif (e.phase == "ended")then

			objeto:applyLinearImpulse((e.xStart - e.x)*(forca/1000), (e.yStart - e.y)*(forca/1000), objeto.x, objeto.y)
			display.getCurrentStage():setFocus(nil)

		end
	end
	objeto:addEventListener("touch",arrastaObjeto)
end

function criarBolaDeArremesso(raioBotao,xBotao,yBotao,imagemBola,xBola,yBola,raio,atrito,elasticidade,forca,r,g,b,a)
	local botao = display.newCircle(xBotao,yBotao,raioBotao)
	botao:setFillColor(0.8,0,0)
	local letra = display.newImage("bola.png",botao.x,botao.y,native.systemFont,raioBotao)
	
	local function criarBolaAux()
		local bola = display.newImage(imagemBola,xBola,yBola)
		physics.addBody(bola,"dinamic",{radius=raio,friction = atrito,bounce=elasticidade})
	
		vida.arremessar(bola,forca,r,g,b,a)
	end
	botao:addEventListener("tap",criarBolaAux)
end

function arremessarComSom(objeto,forca,r,g,b,a,som)
	objSom = audio.loadSound(som)
	function arrastaObjeto(e)
		vida.criarLinha(BolaDePelo,e,r,g,b,a)

		if(e.phase == "began")then

			display.getCurrentStage():setFocus(objeto)

		elseif (e.phase == "ended")then
			audio.play(objSom)
			objeto:applyLinearImpulse((e.xStart - e.x)*forca, (e.yStart - e.y)*forca, objeto.x, objeto.y)
			display.getCurrentStage():setFocus(nil)

		end
	end
	objeto:addEventListener("touch",arrastaObjeto)
end

function criaObstaculoTorre(figura,posX,posY,larg,alt,colunas,linhas)
	for i = 0, colunas-1 do
		for j = 0, linhas do
			bloco = display.newImageRect(figura,larg,alt)
			bloco.x = posX+i*bloco.width
			bloco.y = posY-bloco.height*j
			physics.addBody(bloco,"dynamic",{friction = 1,bounce = .1, density = .3})
		end
	end
end

function criaObstaculoPiramide(figura,posX,posY,larg,alt,valor)
	if valor < -3 then
	 	valor = -3
	 end
	posY = posY - (((4+valor)*larg)+((3+valor)*alt))
	caixa = {}
	caixa2 = {}
	k = 0
	k2 = 0
	for i = 0, 3+valor do
		for j = 0,i+1 do
			local caixa = display.newImageRect(figura,larg,alt)
			caixa:setFillColor(1,0,0)
			local x = posX + (caixa.height *(j - i/2))
			local y = posY +i* caixa.height*1.5
			caixa.x = x
			caixa.y = y
			print("caixa do i X = ".. caixa.x.." Y = ".. caixa.y)
			physics.addBody(caixa, "dynamic",{bounce = .1, friction = 1, density = .3})
			if j<i+1 then
				local caixa2 = display.newImageRect(figura,larg,alt)
				--caixa:setFillColor(.7,.7,0)
				caixa2.rotation = 90
				caixa2.x = caixa.x+ caixa.height/2
				caixa2.y = caixa.y- caixa.height
				print("caixa do j X = ".. caixa.x.." Y = ".. caixa.y)
				physics.addBody(caixa2, "dynamic",{bounce = .1, friction = 1, density = .3})
			end
		end
	end
end

function criaObstaculoQuebravel(posX,posY,larg,alt,colunas,linhas)
	for i = 0, colunas-1 do
		for j = 0, linhas-1 do
			bloco = display.newRect(0,0,larg,alt)
			bloco:setFillColor(0,0,0)
			bloco.x = posX+i*bloco.width
			bloco.y = posY-bloco.height*j
			physics.addBody(bloco,"dynamic",{friction = 1,bounce = .1, density = .3})
		end
	end
end


function somAoColidirControlado(objeto,somObjeto,threshold)
	function somAoColidirAux(e)
		if e.phase == "began" then
			-- if velocidade > threshold then
			-- 	audio.play(somColisoes)
			-- end
			vx,vy = objeto:getLinearVelocity()
			velocidade = math.sqrt(vx*vx+vy*vy)
			print("Velocidade = ".. velocidade)
			if velocidade < threshold then
		        print("CRASH NO SOUND")
		        return
		    end
			local volume = 0
		    local chan = 0
		 
		    if velocidade >= threshold*3 then
		        chan = LOUDEST_ROCK_CHANNEL
		        print("CRASH LOUDEST")
		        volume = 0.5
		    elseif velocidade    >= threshold*2 then
		        chan = LOUD_ROCK_CHANNEL
		        print("CRASH LOUD")
		        volume = 0.4
		    elseif velocidade    >= threshold*1.5 then
		        chan = NORMAL_ROCK_CHANNEL
		        print("CRASH NORMAL")
		        volume = 0.3
		    elseif velocidade >= threshold*1.25 then
		        chan = QUIET_ROCK_CHANNEL
		        print("CRASH QUIET")
		        volume = 0.2
		    elseif velocidade >= threshold then
		        chan = QUIETEST_ROCK_CHANNEL
		        print("CRASH QUIETEST")
		        volume = 0.1
		    end
		    local options = { channel = chan }
 
    		audio.setVolume(volume, options)
    		audio.play(somObjeto, options)
		end
	end
	objeto:addEventListener("collision",somAoColidirAux)
end
-- function somAoColidirControlado2(objeto,som, force, velocity, threshold)
-- 	function somAoColidirControladoAux(e)
-- 		if e.phase == "began" then
-- 			velocidade = objeto:getLinearVelocity()

-- 		    local factor = force*velocidade
		 
-- 		    print("CRASH = " .. tostring(math.floor(factor*10)/10))
		 
-- 		    if factor < threshold then
-- 		        print("CRASH NO SOUND")
-- 		        return
-- 		    end
		 
-- 		    local volume = 0
-- 		    local chan = 0
		 
-- 		    if factor >= threshold*3 then
-- 		        chan = LOUDEST_ROCK_CHANNEL
-- 		        print("CRASH LOUDEST")
-- 		        volume = 0.5
-- 		    elseif factor    >= threshold*2 then
-- 		        chan = LOUD_ROCK_CHANNEL
-- 		        print("CRASH LOUD")
-- 		        volume = 0.4
-- 		    elseif factor    >= threshold*1.5 then
-- 		        chan = NORMAL_ROCK_CHANNEL
-- 		        print("CRASH NORMAL")
-- 		        volume = 0.3
-- 		    elseif factor >= threshold*1.25 then
-- 		        chan = QUIET_ROCK_CHANNEL
-- 		        print("CRASH QUIET")
-- 		        volume = 0.2
-- 		    elseif factor >= threshold then
-- 		        chan = QUIETEST_ROCK_CHANNEL
-- 		        print("CRASH QUIETEST")
-- 		        volume = 0.1
-- 		    end
		 
-- 		    local options = { channel = chan }
		 
-- 		    audio.setVolume(volume, options)
-- 		    playSound(snd, options)
-- 		end
-- 	end
--     objeto:addEventListener("collision", somAoColidirControladoAux)
-- end

function criaObstaculoPiramideComSom(figura,posX,posY,larg,alt,som,valor)
	if valor < -3 then
	 	valor = -3
	 end
	posY = posY - (((4+valor)*larg)+((3+valor)*alt))
	caixa = {}
	caixa2 = {}
	k = 0
	k2 = 0
	for i = 0, 3+valor do
		for j = 0,i+1 do
			print("caixa k = "..k)
			caixa[k] = display.newImageRect(figura,larg,alt)
			caixa[k]:setFillColor(1,0,0)
			local x = posX + (caixa[k].height *(j - i/2))
			local y = posY +i* caixa[k].height*1.5
			caixa[k].x = x
			caixa[k].y = y
			print("caixa do i X = ".. caixa[k].x.." Y = ".. caixa[k].y)
			physics.addBody(caixa[k], "dynamic",{bounce = .1, friction = 1, density = .3})
			somAoColidirControlado(caixa[k],som,150)
			k = k+1
			if j<i+1 then
				print("caixa2 k = "..k2)
				caixa2[k2] = display.newImageRect(figura,larg,alt)
				--caixa2[k2]:setFillColor(.7,.7,0)
				caixa2[k2].rotation = 90
				caixa2[k2].x = caixa[k-1].x+ caixa[k-1].height/2
				caixa2[k2].y = caixa[k-1].y- caixa[k-1].height
				somAoColidirControlado(caixa2[k2],som,150)
				print("caixa do j X = ".. caixa2[k2].x.." Y = ".. caixa2[k2].y)
				physics.addBody(caixa2[k2], "dynamic",{bounce = .1, friction = 1, density = .3})
				k2 = k2+1
			end
		end
	end
end


function criarAnimacaoDupla(k,imagem,numeroDeFrames1,tempoDeAnimacao,contageLoop,caracteristica,animacao1,numeroDeFrames2,tempoDeAnimacao2,contageLoop2,caracteristica2,animacao2)
	numFramesTotal = numeroDeFrames1+numeroDeFrames2
	objeto = display.newImage(imagem,-700,400)
	larguraObjeto = objeto.width
	alturaObjeto = objeto.height
	objeto:removeSelf()
	print(larguraObjeto)
	print(alturaObjeto)
	---------------------------------------------------------------------------------------------
	---------------------------------------------------------------------------------------------
		sheetInfo = {}
		sheetInfo[k] = {
		  width = larguraObjeto/numFramesTotal,
		  height = alturaObjeto,
		  numFrames = numFramesTotal
		}
		bolaSheet = {}
		bolaSheet[k] = graphics.newImageSheet(imagem,sheetInfo[k])

		sequenciaInfo = {}
		sequenciaInfo[k] =
		{
			{
				name = animacao1,
				start = 1,
				count = numeroDeFrames1,
				time = tempoDeAnimacao,
				loopCount = contageLoop,
				loopDirection = caracteristica,
			},
			{
				name = animacao2,
				start = numeroDeFrames1+1,
				count = numFramesTotal,
				time = tempoDeAnimacao2,
				loopCount = contageLoop2,
				loopDirection = caracteristica2,
			}
		}
	local bola = display.newSprite(bolaSheet[k],sequenciaInfo[k]) 
	bola:setSequence(animacao1)
	bola:play()
	return bola
end
-- function inimigoSimples(textoPontos,pontos,objeto)
-- 	function marcarPontosAux(e)
-- 		print(e.other.tipo)
-- 		if e.phase == "ended" then
-- 				if e.other.tipo == "personagem" then
-- 					pontos = pontos + 1
-- 					print(pontos)
-- 					textoPontos.text = "Pontos: " .. pontos
-- 					posX = e.other.x
-- 					posY = e.other.y
-- 					objeto:removeSelf()
-- 				end
-- 		end
-- 	end
-- 	objeto:addEventListener("collision",marcarPontosAux)
-- end

function inimigoSimples(objeto,modificador)
	function marcarPontosAux(e)
		print(e.other.tipo)
		if e.phase == "began" then
				if e.other.tipo == "+" then
					posX = e.other.x
					posY = e.other.y
					if modificador == "aumenta" or modificador == nil then
						if _contagemPontos then
							_contagemPontos = _contagemPontos +1
						end
					elseif modificador == "-" then
						if _contagemPontos then
							_contagemPontos = _contagemPontos -1
						end
					end
					objeto:removeSelf()
				end
		end
	end
	objeto:addEventListener("collision",marcarPontosAux)
end

function inimigoSimplesComSom(objeto,som,modificador)
	function marcarPontosAux(e)
		print(e.other.tipo)
		if e.phase == "began" then
				if e.other.tipo == "personagem" then
					posX = e.other.x
					posY = e.other.y
					if modificador == "aumenta" or modificador == nil then
						if _contagemPontos then
							_contagemPontos = _contagemPontos +1
							audio.play(som)
						end
					elseif modificador == "-" then
						if _contagemPontos then
							_contagemPontos = _contagemPontos -1
							audio.play(som)
						end
					end
					objeto:removeSelf()
				end
		end
	end
	objeto:addEventListener("collision",marcarPontosAux)
end

function inimigoEngorda(objeto)
	function marcarPontosAux(e)
		print(e.other.tipo)
		if e.phase == "began" then
				if e.other.tipo == "personagem" then
					posX = e.other.x
					posY = e.other.y
					if _contagemPontos then
						_contagemPontos = _contagemPontos +1
					end
					objeto:removeSelf()
					e.other.xScale = e.other.xScale + 0.2
					e.other.yScale = e.other.yScale + 0.2
				end
		end
	end
	objeto:addEventListener("collision",marcarPontosAux)
end
function inimigoPiscaExplode(objeto,_animacao,frequenciaDePiscarSegundos)
		function piscarNovamente()
			local randomico = math.random(0,5)
			if randomico < 4 then
				objeto:play()
			end
		end
		objeto.tempo = timer.performWithDelay(frequenciaDePiscarSegundos*1000,piscarNovamente,-1)
	function marcarPontosAux(e)
		print(e.other.tipo)
		if e.phase == "began" then
				if e.other.tipo == "personagem" and objeto.tipo == "inimigo"then
					if _contagemPontos then
						_contagemPontos = _contagemPontos +1
					end
					posX = e.other.x
					posY = e.other.y
					timer.cancel(objeto.tempo)
					objeto.isBodyActive = false
					objeto.isSensor = true
					objeto.isAwake = false
					objeto.tipo = nil
					objeto:setSequence(_animacao)
					objeto:play()
					timer.performWithDelay(350,function() objeto:removeSelf() end,1)
				end
		end
	end
	objeto:addEventListener("collision",marcarPontosAux)
end