  #include<stdio.h>  
  #include<GL/glut.h>  
  #include<math.h>  
  int r,x1,y11;
 
void putpixel(int x,int y)  
  {  
       glBegin(GL_POINTS);  
       glVertex2i(x,y);  
       glEnd();  
       glFlush();  
  } 

  void cir(int x1,int y11,int r)  
  {  
        int x=0,y=r;
	int d=3-2*r;
        do{  
        putpixel(x+x1, y+y11);                   
        putpixel(y+x1, x+y11);  
        putpixel(-x+x1, y+y11);  
        putpixel(-x+x1, -y+y11);  
        putpixel(-y+x1, x+y11);  
        putpixel(-y+x1, -x+y11);  
        putpixel(y+x1, -x+y11);  
        putpixel(x+x1, -y+y11);  
            if(d<0)  
                 d=d+(4*x)+6;  
            else{  
                 d=d+(4*(x-y))+10;  
                 y--;  
            }  
            x++;  
       } while(x<=y);
  }  


 void myinit()  
  {  
        glClearColor(0.0,0.0,0.0,0.0);
	gluOrtho2D(-600.0,600.0,-600.0,600.0);
        glClear(GL_COLOR_BUFFER_BIT);  
  } 
  int main(int argc,char** argv)  
  {  
	
        printf("\nenter centre  of circle");
	scanf("%d%d",&x1,&y11); 
        printf("\nenter radius of circle");
	scanf("%d",&r);       
	glutInit(&argc,argv);  
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  
        glutInitWindowSize(800,800);  
        glutCreateWindow("Bresenham-Circle"); 
         myinit();
	
        cir(x1,y11,r);
        cir(x1-2*r,y11,r);
	cir(x1+2*r,y11,r);
	cir(x1+r,y11+sqrt(3)*r,r);
	cir(x1-r,y11+sqrt(3)*r,r);
	cir(x1+r,y11-sqrt(3)*r,r);
	cir(x1-r,y11-sqrt(3)*r,r);
	cir(x1,y11,r*2);
        glutMainLoop();  
        return 0;  
  }  








