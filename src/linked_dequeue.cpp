#include "linked_dequeue.hpp"

#include <stdexcept>  // logic_error

namespace itis {

void LinkedDequeue::Enqueue(Element e) {
  // TODO: напишите здесь свой код ...
  auto *n_node = new DoublyNode(e,back_, nullptr);
  if (size() != 0) {
      back_->next = n_node;

  } else {
      n_node->previous = nullptr;
      front_ = n_node;
  }
  back_ = n_node;
  size_++;
}

void LinkedDequeue::EnqueueFront(Element e) {
  // TODO: напишите здесь свой код ...
  auto *n_node = new DoublyNode(e, nullptr, front_);
  if (size() != 0) {
      front_->previous = n_node;
  } else {
      n_node->next = nullptr;
      back_ = n_node;
  }
  front_ = n_node;
  size_++;
}

void LinkedDequeue::Dequeue() {
  if (size_ == 0) {
    throw std::logic_error("cannot not dequeue from empty queue");
  }

  // TODO: напишите здесь свой код ...
  if (size() == 1) {
      front_ = nullptr;
      back_ = nullptr;
      size_--;
      return;
  }
  front_ = front_->next;
  delete front_->previous;
  front_->previous = nullptr;
  size_--;
}

void LinkedDequeue::DequeueBack() {
  if (size_ == 0) {
    throw std::logic_error("cannot not dequeue from empty queue");
  }

  // TODO: напишите здесь свой код ...
  if (size() == 1) {
      front_ = nullptr;
      back_ = nullptr;
      size_--;
      return;
  }
  back_ = back_->previous;
  delete back_->next;
  back_->next = nullptr;
  size_--;
}

void LinkedDequeue::Clear() {
  // TODO: напишите здесь свой код ...
  while (front_ != nullptr) {
      Dequeue();
  }
}

// === РЕАЛИЗОВАНО ===

LinkedDequeue::~LinkedDequeue() {
  Clear();
}

std::optional<Element> LinkedDequeue::front() const {
  return front_ == nullptr ? std::nullopt : std::make_optional(front_->data);
}

std::optional<Element> LinkedDequeue::back() const {
  return back_ == nullptr ? std::nullopt : std::make_optional(back_->data);
}

bool LinkedDequeue::IsEmpty() const {
  return size_ == 0;
}

int LinkedDequeue::size() const {
  return size_;
}

// === НЕОБХОДИМО ДЛЯ ТЕСТИРОВАНИЯ ===

std::ostream &operator<<(std::ostream &os, const LinkedDequeue &queue) {
  os << "size: " << queue.size_ << '\n';
  for (auto current_node = queue.front_; current_node != nullptr; current_node = current_node->previous) {
    if (current_node == queue.front_) os << "[FRONT] ";
    if (current_node == queue.back_) os << "[BACK] ";
    os << enum2str(current_node->data) << '\n';
  }
  return os;
}

}  // namespace itis
