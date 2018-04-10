#include "lib/cpen.h"
#include <stdlib.h>
#include <lib/pen.h>

void triangulo(Pen &p, int lado){
    if(lado<10)
        return;
    for(int i=0; i<3; i++){
        p.walk(lado);
        p.left(120);
        triangulo(p, lado/2);
        p.setColor(rand()%255, rand()%255, rand()%255);
    }
}

void arvore1(Pen& p, int lado, int ax_lado){
    float ang = 35;
    float dec = 0.75;
    lado -= (p.rand() % 7 - 3);
    if(lado < 10)
        return;

    p.setColor(rand()%255,205,50);
    if(((ax_lado/100)*90)==lado/100){
        ax_lado-=25;
        if(ax_lado%2==0){
            p.setColor(199,21,133);
        }
    }

    p.walk(lado);
    p.right(ang);
    arvore1(p, lado * dec, ax_lado);
    p.left(ang);
    arvore1(p, lado * dec, ax_lado);
    p.left(ang);
    arvore1(p, lado * dec, ax_lado);
    p.right(ang);

    if(lado%3==0){
        p.setColor(210,105,30);
    }

    p.walk(-lado);
}

void arvore2(Pen& p, int lado){
    float ang = 35;
    float dec = 0.75;
    lado -= lado/20;
    if(lado < 10)
        return;

    p.setColor(rand()%255,205,50);
    p.walk(lado);
    p.right(ang);
    arvore2(p, lado * dec);
    p.left(ang);
    arvore2(p, lado * dec);
    p.left(ang);
    arvore2(p, lado * dec);
    p.right(ang);
    if(lado%3==0){
        p.setColor(210,105,30);
    }
    p.walk(-lado);
}


void trigo(Pen &p, int lado){
    int x=0;
    int angulo=60;
    if(lado<1)
        return;
    while (x!=4) {
        p.walk(lado);
        p.right(angulo);
        trigo(p,lado/3);
        p.left(2*angulo);
        trigo(p,lado/3);
        p.right(angulo);
        x++;
        p.setColor(255,rand()%215,0);
    }
    p.walk(-lado*x);
}

void pentagono(Pen &p, int lado){
    int angulo=72;
    if(lado<6)
        return;
    p.setColor(0, rand()%255, 108);
    for(int i=0; i<5; i++){
        p.walk(lado);
        p.left(angulo);
        pentagono(p, lado/3);
        p.setColor(0, rand()%255, 108);
    }

}

void estrela(Pen &p, int lado){
    int angulo = 144;
    if(lado<6)
        return;

    p.setColor(rand()%255, 0, 200);

    for(int i=0; i<5; i++){
        p.walk(lado);
        p.left(angulo);
        p.walk(lado);
        estrela(p, lado/3);
        p.walk(-lado);
        p.setColor(rand()%255, 0, 200);
    }
}

/** Árvore **/
void fractal_a1(){
    /** Árvore **/
    Pen p(800, 600);
    p.setThickness(2);
    //coloca o pincel na posicao x 300 y 500
    p.setXY(400, 500);

    //faz o pincel apontar pra direita
    p.setHeading(90);
    //se speed = 0 entao ele faz o mais rapido possivel
    //se foi a partir de 1 ele controla a velocidade
    p.setSpeed(1000);

    arvore1(p, 80, 80);
    //triangulo(p, 400);
    //espera clicar no botao de fechar
    p.wait();
}

void fractal_a2(){
    /** Árvore **/
    Pen p(800, 600);
    p.setThickness(2);
    //coloca o pincel na posicao x 300 y 500
    p.setXY(400, 500);

    //faz o pincel apontar pra direita
    p.setHeading(90);
    //se speed = 0 entao ele faz o mais rapido possivel
    //se foi a partir de 1 ele controla a velocidade
    p.setSpeed(100);

    arvore2(p, 140);
    //triangulo(p, 400);
    //espera clicar no botao de fechar
    p.wait();
}

/** Triângulo **/
void fractal_tl(){
    Pen p(1000, 800);
    p.setThickness(2);
    p.setXY(200, 590);
    p.setHeading(0);
    p.setSpeed(200);
    triangulo(p, 400);
    p.wait();
}

/** Trigo **/
void fractal_tr(){
    Pen p(800, 600);
    int lado = 100;
    p.setXY(300, 600);
    p.setColor(255,255,255);
    p.setHeading(90);
    p.setSpeed(20);
    p.setThickness(1);
    trigo(p,lado);
    p.wait();
}

/** Pentagono **/
void fractal_p(){
    Pen p(1000, 800);
    p.setThickness(2);
    p.setXY(250, 400);
    p.setHeading(0);
    p.setSpeed(20);
    pentagono(p, 200);
    p.wait();
}

/** Estrela **/
void fractal_e(){
    Pen p(1200, 1200);
    p.setThickness(2);
    p.setXY(350, 400);
    p.setHeading(0);
    p.setSpeed(20);
    estrela(p, 400);
    p.wait();
}

int main(){
    //fractal_a1();
    //fractal_a2();
    //fractal_tl();
    //fractal_tr();
    //fractal_p();
    fractal_e();
    return 0;
}
