// #import "interface.hpp"

// void App::render() {
//     // Clear the color and depth buffers of the frame buffer
//     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//     glMatrixMode(GL_MODELVIEW);
//     glLoadIdentity();

//     // render exemple quad
//     // glColor3f(1.0f, 0.0f, 0.0f);
//     // glBegin(GL_QUADS);
//     //     glVertex2f(-0.5f, -0.5f);
//     //     glVertex2f(0.5f, -0.5f);
//     //     glVertex2f(0.5f, 0.5f);
//     //     glVertex2f(-0.5f, 0.5f);
//     // glEnd();

//     glPushMatrix();
//     glScalef(0.8f, 0.8f, 0.8f);
//     //glRotatef(_angle, 0.0f, 0.0f, 1.0f);
//     //draw_quad_with_texture(_texture);
//     glPopMatrix();

//     //TextRenderer.Label("Example of using SimpleText library", _width / 2, 20, SimpleText::CENTER);

//     // Without set precision
//     // const std::string angle_label_text { "Angle: " + std::to_string(_angle) };
//     // With c++20 you can use std::format
//     // const std::string angle_label_text { std::format("Angle: {:.2f}", _angle) };

//     // Using stringstream to format the string with fixed precision
//     std::string angle_label_text {};
//     std::stringstream stream {};
//     stream << std::fixed << "Angle: " << std::setprecision(2) << _angle;
//     angle_label_text = stream.str();

//     //TextRenderer.Label(angle_label_text.c_str(), _width / 2, _height - 4, SimpleText::CENTER);

//     TextRenderer.Render();
// }