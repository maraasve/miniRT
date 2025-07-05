# 🖼️ miniRT

`miniRT` is a minimal ray tracer developed as part of the 42 curriculum. It renders 3D scenes by simulating the way light interacts with geometric objects, following the fundamentals of ray tracing. The project supports basic shapes (cylinder, sphere, plane), lighting, and camera functionality.

---

## 🛠️ Features

- ✅ **Scene parsing** from `.rt` files  
- 📷 **Camera** with configurable field of view and transformations  
- ☀️ **Ambient, point, and directional lighting**
- 🔺 **Basic geometric primitives:**
  - Spheres
  - Planes
  - Cylinders
- 🌈 **RGB color support**
- 🧮 **Vector and matrix operations**
- 🧪 **Ray-object intersection calculations**
- 🖨️ **BMP image export** (optional, depending on implementation)

---

## 📦 How to Use

### 🔧 Build the project
To compile the ray tracer without bonus:

```bash
make
```

To compile the ray tracer with bonus:

```bash
make
```

### ▶️ Run the program

```bash
./minirt_bonus ./maps/mulit_lights.rt
```

![img](./img/multi_lights.png)