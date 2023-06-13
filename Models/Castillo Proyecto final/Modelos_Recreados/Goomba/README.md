# Goomba/Codigo
//Declaraciones
float CaminataGoomba = 0.0f;
bool SentidoGoomba = false;
float rotCabezaGoomba = 0.0f;
float rotPieDerGoomba = 0.0f;
float rotPieIzqGoomba = 0.0f;
bool RotSentidoGoomba = false;
//Carga de modelo
		model = glm::mat4(1);
        model = glm::translate(model, glm::vec3(6.453f + CaminataGoomba, 0.386f, -7.696f));
        model = glm::rotate(model, glm::radians(rotCabezaGoomba), glm::vec3(0.0f, 0.5f, 1.0f));
        glUniformMatrix4fv(glGetUniformLocation(shader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
        GoombaCabeza.Draw(shader);
        model = glm::mat4(1);
        model = glm::translate(model, glm::vec3(6.453f + CaminataGoomba, 0.386f, -7.696f));
        model = glm::rotate(model, glm::radians(rotPieDerGoomba), glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(glGetUniformLocation(shader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
        GoombaPieDer.Draw(shader);
        model = glm::mat4(1);
        model = glm::translate(model, glm::vec3(6.453f + CaminataGoomba, 0.386f, -7.696f));
        model = glm::rotate(model, glm::radians(rotPieIzqGoomba), glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(glGetUniformLocation(shader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
        GoombaPieIzq.Draw(shader);
//Funciones
    if(SentidoGoomba==false)
    {
        CaminataGoomba += 0.0001f;
        if (CaminataGoomba > 0.647f)
        {
            SentidoGoomba = true;
        }
    }
    if (SentidoGoomba == true)
    {
        CaminataGoomba -= 0.0001f;
        if (CaminataGoomba < -0.936f)
        {
            SentidoGoomba = false;
        }
    }

    if (RotSentidoGoomba == false)
    {
        rotCabezaGoomba += 0.03f;
        if (rotCabezaGoomba > 10.0f)
        {
            RotSentidoGoomba = true;
        }
    }
    if (RotSentidoGoomba == true)
    {
        rotCabezaGoomba -= 0.03f;
        if (rotCabezaGoomba < -10.0f)
        {
            RotSentidoGoomba = false;
        }
    }
	if (rotCabezaGoomba<0.0f)
	{
		rotPieIzqGoomba=0.0f
		rotPieDerGoomba=2*rotCabezaGoomba
	}
	if (rotCabezaGoomba>0.0f)
	{
		rotPieDerGoomba=0.0f
		rotPieIzqGoomba=2*rotCabezaGoomba
	}