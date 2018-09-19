//
// Created by shaggy on 9/17/18.
//

#include "camera.h"

Camera::Camera()
{
    eye0.vertex = glm::vec4(-2.f, 0.f, 0.f, 1.f);
    eye1.vertex = glm::vec4(-1.f, 0.f, 0.f, 1.f);
}

Camera::~Camera() {}

void Camera::Render()
{
    float t = 2.f;
    Vertex eye = eye1;

    for (int i = 0; i < 800; ++i)
    {
        for (int j = 0; j < 800; ++j)
        {
            Ray* pixelRay = new Ray();
            screen[j][i].ray = pixelRay;
            pixelRay->start.vertex = eye.vertex;
            pixelRay->end.vertex = eye.vertex + t * (glm::vec4(0.0f, j * 0.0025f - 0.99875, i * 0.0025f - 0.99875, 1.0f) - eye.vertex);
            scene.FindInstersections(pixelRay);
            screen[j][i].colInt = pixelRay->color;
        }
    }
}

void Camera::CreateImage()
{
    int w = 800;
    int h = 800;
    FILE *f;
    unsigned char *img = NULL;
    int filesize = 54 + 3 * w*h;

    img = (unsigned char *)malloc(3 * w * h);
    memset(img, 0, 3 * w * h);

    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
        {
            int x = i;
            int y = (h - 1) - j;
            int r = this->screen[i][j].colInt.color.x;
            int g = this->screen[i][j].colInt.color.y;
            int b = this->screen[i][j].colInt.color.z;
            if (r > 255) r = 255;
            if (g > 255) g = 255;
            if (b > 255) b = 255;
            img[(x + y * w) * 3 + 2] = (unsigned char)(r);
            img[(x + y * w) * 3 + 1] = (unsigned char)(g);
            img[(x + y * w) * 3 + 0] = (unsigned char)(b);
        }
    }

    unsigned char bmpfileheader[14] = { 'B','M', 0,0,0,0, 0,0, 0,0, 54,0,0,0 };
    unsigned char bmpinfoheader[40] = { 40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0, 24,0 };
    unsigned char bmppad[3] = { 0,0,0 };

    bmpfileheader[2] = (unsigned char)(filesize);
    bmpfileheader[3] = (unsigned char)(filesize >> 8);
    bmpfileheader[4] = (unsigned char)(filesize >> 16);
    bmpfileheader[5] = (unsigned char)(filesize >> 24);

    bmpinfoheader[4] = (unsigned char)(w);
    bmpinfoheader[5] = (unsigned char)(w >> 8);
    bmpinfoheader[6] = (unsigned char)(w >> 16);
    bmpinfoheader[7] = (unsigned char)(w >> 24);
    bmpinfoheader[8] = (unsigned char)(h);
    bmpinfoheader[9] = (unsigned char)(h >> 8);
    bmpinfoheader[10] = (unsigned char)(h >> 16);
    bmpinfoheader[11] = (unsigned char)(h >> 24);

    f = fopen("img.bmp", "wb");
    fwrite(bmpfileheader, 1, 14, f);
    fwrite(bmpinfoheader, 1, 40, f);
    for (int i = 0; i<h; i++)
    {
        fwrite(img + (w*(h - i - 1) * 3), 3, w, f);
        fwrite(bmppad, 1, (4 - (w * 3) % 4) % 4, f);
    }

    free(img);
    fclose(f);

}
