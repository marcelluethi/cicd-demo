FROM gcc:13.2.0

# Install build tools
RUN apt-get update && apt-get install -y \
    libpthread-stubs0-dev \
    cmake


# Set working directory
WORKDIR /app

# Copy the source code into the container
COPY . .

# Build the project using CMake or any other tool
RUN mkdir -p build && cd build && cmake .. && make

# Expose the port the server listens on (replace 8080 with your server's port)
EXPOSE 8080

# Set the default command to run the server (adjust the path if necessary)
CMD ["./build/src/hello_world_server"]